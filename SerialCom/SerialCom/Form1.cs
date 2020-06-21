using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SerialCom
{
    public partial class 串口小程序 : Form
    {
        public 串口小程序()
        {
            InitializeComponent();


        }

        //创建 串口 对象 serialPort
        private SerialPort serialPort = new SerialPort();
        System.Timers.Timer timer = new System.Timers.Timer();
        public delegate void SetControlValue(string value);
        // 连接成功标志位
        bool connected_port = false;

        bool time_flag = false;

        bool null_flag = false;
        private void Form1_Load(object sender, EventArgs e)
        {

            //取消最大化按键
            this.MaximizeBox = false;

            button1.Text = "打开串口";
            serialStatus.Text = "请连接串口";
            serialStatus.ForeColor = Color.Red;
            showCN.Checked = true;

            

            //加载列表信息
            listInit();
            //加载串口信息
            ReloadPort();

            TimerInit();

            
        }

        /*  设置串口设置列表信息  */
        public void listInit()
        {
            //添加常用波特率
            setBaundRate.Items.Add("1200");
            setBaundRate.Items.Add("2400");
            setBaundRate.Items.Add("4800");
            setBaundRate.Items.Add("9600");
            setBaundRate.Items.Add("19200");
            setBaundRate.Items.Add("38400");
            setBaundRate.Items.Add("43000");
            setBaundRate.Items.Add("56000");
            setBaundRate.Items.Add("57600");
            setBaundRate.Items.Add("115200");
            setBaundRate.Items.Add("117600");
            setBaundRate.Items.Add("240000");
            setBaundRate.SelectedIndex = 3;

            //添加停止位
            setStopBits.Items.Add("0");
            setStopBits.Items.Add("1");
            setStopBits.Items.Add("1.5");
            setStopBits.Items.Add("2");
            setStopBits.SelectedIndex = 1;

            //添加校验位
            setParity.Items.Add("None (无)");
            setParity.Items.Add("Odd (偶)");
            setParity.Items.Add("Even (奇)");
            setParity.Items.Add("Mark (=1)");
            setParity.Items.Add("Space (=0)");
            setParity.SelectedIndex = 0;

            //添加数据位
            setDataBits.Items.Add("8");
            setDataBits.Items.Add("9");
            setDataBits.SelectedIndex = 0;
        }
        /*  重新加载串口号  */
        public void ReloadPort()
        {
            //使用 SerialPort 的 GetPortNames 方法获取可用串口号
            string[] ports = SerialPort.GetPortNames();
            //清除串口号列表控件内容
            setPort.Items.Clear();
            // 如果有可用串口
            if (0 != ports.Length)
            {
                //排序串口列表, 从小到大
                Array.Sort(ports);
                //添加串口号列表控件内容
                setPort.Items.AddRange(ports);
                //三元  如果串口数大于零，默认显示第一个， 小于零 显示 -1 （error）
                setPort.SelectedIndex = setPort.Items.Count > 0 ? 0 : -1;

            }
            else//没有可用串口
            {
                MessageBox.Show("没有找到可用串口");
                setPort.SelectedIndex = setPort.Items.Count > 0 ? 0 : -1;
            }

        }
        /*  检查设置信息是否有空  */
        public bool CheckPortSetting()
        {
            if (0 == setPort.Text.Length) return false;
            if (0 == setBaundRate.Text.Length) return false;
            if (0 == setStopBits.Text.Length) return false;
            if (0 == setDataBits.Text.Length) return false;
            if (0 == setParity.Text.Length) return false;

            return true;

        }

        /*  串口信息设置   */
        public void SettingPort()
        {
            //检查串口信息设置
            if (true == CheckPortSetting())
            {
                //检查串口连接标志，如果为false为没有链接串口
                if (false == connected_port)
                {
                    //停止位信息转换为双精度浮点型
                    double combo_stopbit = Convert.ToSingle(setStopBits.Text.Trim());
                    //获取校验位设置 转换为字符串
                    string combo_parity = setParity.Text.Trim();
                    try
                    {
                        //设置串口号
                        serialPort.PortName = setPort.Text;
                        //设置串口波特率
                        serialPort.BaudRate = int.Parse(setBaundRate.Text);
                        //设置停止位
                        switch (combo_stopbit)
                        {
                            case 0:
                                serialPort.StopBits = StopBits.None;
                                break;
                            case 1:
                                serialPort.StopBits = StopBits.One;
                                break;
                            case 1.5:
                                serialPort.StopBits = StopBits.OnePointFive;
                                break;
                            case 2:
                                serialPort.StopBits = StopBits.Two;
                                break;

                            default: break;
                        }
                        //设置数据位
                        serialPort.DataBits = Convert.ToInt16(setDataBits.Text);


                        //设置校验位
                        switch (combo_parity)
                        {
                            case "None (无)":
                                serialPort.Parity = Parity.None;
                                break;
                            case "Odd (偶)":
                                serialPort.Parity = Parity.Odd;
                                break;
                            case "Even (奇)":
                                serialPort.Parity = Parity.Even;
                                break;
                            case "Mark (=1)":
                                serialPort.Parity = Parity.Mark;
                                break;
                            case "Space (=0)":
                                serialPort.Parity = Parity.Space;
                                break;
                            default: break;
                        }
                        //  设置超时读取时间
                        serialPort.ReadTimeout = -1;

                        //serialPort.RtsEnable = true;

                        // 定义port_DataReceived 委托事件 C#特性 ，  当串口收到数据后触发委托
                        serialPort.DataReceived += new SerialDataReceivedEventHandler(port_DataReceived);

                        // 打开串口
                        serialPort.Open();
                        button1.Text = "关闭串口";
                        // 连接串口标志 = true
                        connected_port = true;

                        reloadPortBtn.Enabled = false;

                    }
                    catch (Exception ex)
                    {
                        serialPort = new SerialPort();
                        MessageBox.Show(ex.Message);
                    }
                }
                else//为true 连接了串口
                {
                    try
                    {
                        //关闭串口
                        serialPort.Close();
                        button1.Text = "打开串口";
                        //标志置为 false
                        connected_port = false;
                        timeSendMSg.Checked = false;
                        reloadPortBtn.Enabled = true;
                    }
                    catch (Exception ex)
                    {
                        serialPort = new SerialPort();
                        MessageBox.Show(ex.Message);
                    }



                }
            }
            else//串口信息错误
            {
                MessageBox.Show("请设置串口信息");
            }
            if( false == time_flag)
            {
                timer1.Start();
            }else
            {
                timer1.Stop();
            }
            ShowPortValue();
        }

        /*  字符串转HEX  */
        public static byte[] GetHexValue(string str)
        {
            string[] sourceStr = str.Split(' ');
            byte[] converHexByte = new byte[sourceStr.Length];
            try
            {
                for (int i = 0; i < sourceStr.Length; i++)
                {
                    converHexByte[i] = (byte)(int.Parse(sourceStr[i], System.Globalization.NumberStyles.HexNumber));
                }
            }
            catch { }


            return converHexByte;
        }

        /*  发送数据  */
        public void port_DataSend()
        {
            //发送HEX信息
            if (true == sendModeHex.Checked)
            {
                //创建字节数组
                byte[] sendTemp = new byte[sendMsgBox.Text.Length];
                //调用 GetHexValue 函数将字符串转为 HEX 
                sendTemp = GetHexValue(sendMsgBox.Text);
                try
                {
                    serialPort.Write(sendTemp, 0, sendTemp.Length);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
            else//发送字符信息
            {
                try
                {
                    //支持中文
                    //创建编码对象 gb 编码为 gb2312
                    Encoding gb = System.Text.Encoding.GetEncoding("gb2312");
                    //两个字节一个汉字
                    //将 发送字符转为 gb2312 编码字节
                    byte[] write_buf = gb.GetBytes(sendMsgBox.Text);

                    serialPort.Write(write_buf, 0, write_buf.Length);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                }
            }
        }

        
        /*  创建数据接收委托  */
        private void port_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            if (serialPort.IsOpen)
            {
                
                
                //显示字符
                if (true == receivedModeStr.Checked)
                {
                    //支持中文
                    if (true == showCN.Checked)
                    {
                        //关闭禁止跨线程访问
                        CheckForIllegalCrossThreadCalls = false;
                        //创建编码对象gb , 编码为 gb2312
                        Encoding gb = System.Text.Encoding.GetEncoding("gb2312");
                        //创建字节数组 长度为 接收字节长度
                        byte[] read_buf = new byte[serialPort.BytesToRead];
                        //接收数据, 存放在read_buf 字节数据, 从0 开始, 到最后
                        serialPort.Read(read_buf, 0, read_buf.Length);
                        //将read_buf字节数组 用 gb的getstring方法将 字节类型 一个一个转换为字符串
                        String str = gb.GetString(read_buf);
                        //显示接收数据
                        receiveMsgBox.Text += str;
                        //销毁
                        //serialPort.DiscardInBuffer();
                    }else
                    {
                        CheckForIllegalCrossThreadCalls = false;
                        string str = serialPort.ReadExisting();
                        receiveMsgBox.Text += str;

                        //serialPort.DiscardInBuffer();
                    }
                }
                else if (true == receivedModeHex.Checked)//接收HEX
                {
                    //关闭禁止跨线程访问
                    CheckForIllegalCrossThreadCalls = false;

                    //创建 字节数组 对象
                    byte[] read_buf = new byte[serialPort.BytesToRead];
                    // 获取接收信息 存入 read_buf 字节数组
                    serialPort.Read(read_buf, 0, read_buf.Length);

                    String receviedData = null;
                    for (int i = 0; i < read_buf.Length; i++)
                    {
                        // 以指定方式将字节类型转换为HEX字符串 添加到字符串 receviedData 中
                        receviedData += (read_buf[i].ToString("X2") + " ");
                    }
                    receiveMsgBox.Text += receviedData;
                    //清除 销毁 接收信息
                    //serialPort.DiscardInBuffer();
                }
            }
        }

        /*  清除接收区内容  */
        public void ClearRecevieMsgBox()
        {
            receiveMsgBox.Text = "";
        }

        //显示串口信息
        public void ShowPortValue()
        {
            string str = null;
            if (true == connected_port)
            {
                str = serialPort.PortName + "," + serialPort.BaudRate + "," + serialPort.DataBits + "," + serialPort.Parity + "," + serialPort.StopBits;
                serialStatus.Text = str;
            }
            else
            {
                serialStatus.Text = "请连接串口";
            }

        }

        public void TimerInit()
        {
            try
            {
                timer.Enabled = true;
                timer.Elapsed += new System.Timers.ElapsedEventHandler(TimerUp);
            }catch(Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
            
        }

        private void TimerUp(object sender, System.Timers.ElapsedEventArgs e)
        {
            CheckForIllegalCrossThreadCalls = false;
            if (true == timeSendMSg.Checked)
            {
                if (true == serialPort.IsOpen)
                {
                    try
                    {
                        int time = int.Parse(timeSetMS.Text);
                        timer1.Interval = time;
                        if (true == timer1.Enabled)
                        {
                            sendMsgBtn.PerformClick();
                        }
                    }
                    catch (Exception ex)
                    {
                        timer1.Stop();
                        timeSendMSg.Checked = false;
                        timer1.Start();
                        MessageBox.Show(ex.Message);
                    }
                }
                else
                {

                }

            }
            else
            {

            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            SettingPort();

        }


        private void setPort_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void setBaundRate_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void serialStatus_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void sendMsgBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void sendMsgBtn_Click(object sender, EventArgs e)
        {
            port_DataSend();

        }


        private void MsgBox_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void clearReceiveMsgBoxBtn_Click(object sender, EventArgs e)
        {
            ClearRecevieMsgBox();
        }

        private void 选择串口_Click(object sender, EventArgs e)
        {

        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void setStopBits_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void receiveMsgBox_TextChanged(object sender, EventArgs e)
        {

        }

        private void receivedModeHex_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void timeSendMSg_CheckedChanged(object sender, EventArgs e)
        {
            if( true == timeSendMSg.Checked )
            {
                if (true != serialPort.IsOpen)
                {
                    MessageBox.Show("请先连接串口");
                    timeSendMSg.Checked = false;
                }
            }
        }

        private void setDataBits_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void setParity_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void sendModeHex_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void sendModeStr_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void sendMsgBox_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void reloadPortBtn_Click(object sender, EventArgs e)
        {
            ReloadPort();
        }

        private void receivedModeStr_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void groupBox2_Enter(object sender, EventArgs e)
        {

        }

        private void showCN_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void timeSetMS_TextChanged(object sender, EventArgs e)
        {

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            
        }
    }
}
