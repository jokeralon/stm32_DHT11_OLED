namespace SerialCom
{
    partial class 串口小程序
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要修改
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.button1 = new System.Windows.Forms.Button();
            this.setPort = new System.Windows.Forms.ComboBox();
            this.setBaundRate = new System.Windows.Forms.ComboBox();
            this.sendMsgBtn = new System.Windows.Forms.Button();
            this.clearReceiveMsgBoxBtn = new System.Windows.Forms.Button();
            this.串口号 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.label7 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.label5 = new System.Windows.Forms.Label();
            this.reloadPortBtn = new System.Windows.Forms.Button();
            this.setStopBits = new System.Windows.Forms.ComboBox();
            this.setParity = new System.Windows.Forms.ComboBox();
            this.serialStatus = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.setDataBits = new System.Windows.Forms.ComboBox();
            this.label2 = new System.Windows.Forms.Label();
            this.receivedModeHex = new System.Windows.Forms.RadioButton();
            this.receivedModeStr = new System.Windows.Forms.RadioButton();
            this.receiveMsgBox = new System.Windows.Forms.RichTextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.showCN = new System.Windows.Forms.CheckBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.timeSetMS = new System.Windows.Forms.TextBox();
            this.timeSendMSg = new System.Windows.Forms.CheckBox();
            this.label6 = new System.Windows.Forms.Label();
            this.sendMsgBox = new System.Windows.Forms.RichTextBox();
            this.sendModeStr = new System.Windows.Forms.RadioButton();
            this.sendModeHex = new System.Windows.Forms.RadioButton();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(182, 79);
            this.button1.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(95, 93);
            this.button1.TabIndex = 0;
            this.button1.Text = "打开串口";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // setPort
            // 
            this.setPort.FormattingEnabled = true;
            this.setPort.Location = new System.Drawing.Point(64, 23);
            this.setPort.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.setPort.Name = "setPort";
            this.setPort.Size = new System.Drawing.Size(106, 21);
            this.setPort.TabIndex = 3;
            this.setPort.SelectedIndexChanged += new System.EventHandler(this.setPort_SelectedIndexChanged);
            // 
            // setBaundRate
            // 
            this.setBaundRate.FormattingEnabled = true;
            this.setBaundRate.Location = new System.Drawing.Point(64, 54);
            this.setBaundRate.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.setBaundRate.Name = "setBaundRate";
            this.setBaundRate.Size = new System.Drawing.Size(106, 21);
            this.setBaundRate.TabIndex = 4;
            this.setBaundRate.SelectedIndexChanged += new System.EventHandler(this.setBaundRate_SelectedIndexChanged);
            // 
            // sendMsgBtn
            // 
            this.sendMsgBtn.Location = new System.Drawing.Point(188, 98);
            this.sendMsgBtn.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.sendMsgBtn.Name = "sendMsgBtn";
            this.sendMsgBtn.Size = new System.Drawing.Size(115, 33);
            this.sendMsgBtn.TabIndex = 8;
            this.sendMsgBtn.Text = "发送数据";
            this.sendMsgBtn.UseVisualStyleBackColor = true;
            this.sendMsgBtn.Click += new System.EventHandler(this.sendMsgBtn_Click);
            // 
            // clearReceiveMsgBoxBtn
            // 
            this.clearReceiveMsgBoxBtn.Location = new System.Drawing.Point(325, 302);
            this.clearReceiveMsgBoxBtn.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.clearReceiveMsgBoxBtn.Name = "clearReceiveMsgBoxBtn";
            this.clearReceiveMsgBoxBtn.Size = new System.Drawing.Size(168, 40);
            this.clearReceiveMsgBoxBtn.TabIndex = 11;
            this.clearReceiveMsgBoxBtn.Text = "清除内容";
            this.clearReceiveMsgBoxBtn.UseVisualStyleBackColor = true;
            this.clearReceiveMsgBoxBtn.Click += new System.EventHandler(this.clearReceiveMsgBoxBtn_Click);
            // 
            // 串口号
            // 
            this.串口号.AutoSize = true;
            this.串口号.Location = new System.Drawing.Point(3, 26);
            this.串口号.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.串口号.Name = "串口号";
            this.串口号.Size = new System.Drawing.Size(60, 13);
            this.串口号.TabIndex = 12;
            this.串口号.Text = "串口号:";
            this.串口号.Click += new System.EventHandler(this.选择串口_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.label7);
            this.groupBox1.Controls.Add(this.label4);
            this.groupBox1.Controls.Add(this.label5);
            this.groupBox1.Controls.Add(this.reloadPortBtn);
            this.groupBox1.Controls.Add(this.setStopBits);
            this.groupBox1.Controls.Add(this.button1);
            this.groupBox1.Controls.Add(this.setParity);
            this.groupBox1.Controls.Add(this.serialStatus);
            this.groupBox1.Controls.Add(this.label3);
            this.groupBox1.Controls.Add(this.setDataBits);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.串口号);
            this.groupBox1.Controls.Add(this.setBaundRate);
            this.groupBox1.Controls.Add(this.setPort);
            this.groupBox1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.groupBox1.Font = new System.Drawing.Font("黑体", 9.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.groupBox1.Location = new System.Drawing.Point(13, 3);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(306, 199);
            this.groupBox1.TabIndex = 13;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "串口设置";
            this.groupBox1.Enter += new System.EventHandler(this.groupBox1_Enter);
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(3, 181);
            this.label7.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(75, 13);
            this.label7.TabIndex = 21;
            this.label7.Text = "串口状态:";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(3, 119);
            this.label4.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(60, 13);
            this.label4.TabIndex = 19;
            this.label4.Text = "停止位:";
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(2, 88);
            this.label5.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(60, 13);
            this.label5.TabIndex = 18;
            this.label5.Text = "效验位:";
            // 
            // reloadPortBtn
            // 
            this.reloadPortBtn.Location = new System.Drawing.Point(182, 23);
            this.reloadPortBtn.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.reloadPortBtn.Name = "reloadPortBtn";
            this.reloadPortBtn.Size = new System.Drawing.Size(95, 36);
            this.reloadPortBtn.TabIndex = 20;
            this.reloadPortBtn.Text = "检测串口";
            this.reloadPortBtn.UseVisualStyleBackColor = true;
            this.reloadPortBtn.Click += new System.EventHandler(this.reloadPortBtn_Click);
            // 
            // setStopBits
            // 
            this.setStopBits.FormattingEnabled = true;
            this.setStopBits.Location = new System.Drawing.Point(64, 116);
            this.setStopBits.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.setStopBits.Name = "setStopBits";
            this.setStopBits.Size = new System.Drawing.Size(106, 21);
            this.setStopBits.TabIndex = 17;
            this.setStopBits.SelectedIndexChanged += new System.EventHandler(this.setStopBits_SelectedIndexChanged);
            // 
            // setParity
            // 
            this.setParity.FormattingEnabled = true;
            this.setParity.Location = new System.Drawing.Point(64, 85);
            this.setParity.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.setParity.Name = "setParity";
            this.setParity.Size = new System.Drawing.Size(106, 21);
            this.setParity.TabIndex = 16;
            this.setParity.SelectedIndexChanged += new System.EventHandler(this.setParity_SelectedIndexChanged);
            // 
            // serialStatus
            // 
            this.serialStatus.AutoSize = true;
            this.serialStatus.Font = new System.Drawing.Font("黑体", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.serialStatus.Location = new System.Drawing.Point(81, 181);
            this.serialStatus.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.serialStatus.Name = "serialStatus";
            this.serialStatus.Size = new System.Drawing.Size(49, 13);
            this.serialStatus.TabIndex = 5;
            this.serialStatus.Text = "label1";
            this.serialStatus.Click += new System.EventHandler(this.serialStatus_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(2, 150);
            this.label3.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(60, 13);
            this.label3.TabIndex = 15;
            this.label3.Text = "数据位:";
            // 
            // setDataBits
            // 
            this.setDataBits.FormattingEnabled = true;
            this.setDataBits.Location = new System.Drawing.Point(64, 147);
            this.setDataBits.Margin = new System.Windows.Forms.Padding(6, 5, 6, 5);
            this.setDataBits.Name = "setDataBits";
            this.setDataBits.Size = new System.Drawing.Size(106, 21);
            this.setDataBits.TabIndex = 14;
            this.setDataBits.SelectedIndexChanged += new System.EventHandler(this.setDataBits_SelectedIndexChanged);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(4, 57);
            this.label2.Margin = new System.Windows.Forms.Padding(6, 0, 6, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(60, 13);
            this.label2.TabIndex = 13;
            this.label2.Text = "波特率:";
            // 
            // receivedModeHex
            // 
            this.receivedModeHex.AutoSize = true;
            this.receivedModeHex.Location = new System.Drawing.Point(107, 313);
            this.receivedModeHex.Name = "receivedModeHex";
            this.receivedModeHex.Size = new System.Drawing.Size(79, 18);
            this.receivedModeHex.TabIndex = 22;
            this.receivedModeHex.Text = "HEX显示";
            this.receivedModeHex.UseVisualStyleBackColor = true;
            this.receivedModeHex.CheckedChanged += new System.EventHandler(this.receivedModeHex_CheckedChanged);
            // 
            // receivedModeStr
            // 
            this.receivedModeStr.AutoSize = true;
            this.receivedModeStr.Checked = true;
            this.receivedModeStr.Location = new System.Drawing.Point(210, 313);
            this.receivedModeStr.Name = "receivedModeStr";
            this.receivedModeStr.Size = new System.Drawing.Size(85, 18);
            this.receivedModeStr.TabIndex = 23;
            this.receivedModeStr.TabStop = true;
            this.receivedModeStr.Text = "字符显示";
            this.receivedModeStr.UseVisualStyleBackColor = true;
            this.receivedModeStr.CheckedChanged += new System.EventHandler(this.receivedModeStr_CheckedChanged);
            // 
            // receiveMsgBox
            // 
            this.receiveMsgBox.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.receiveMsgBox.Location = new System.Drawing.Point(14, 23);
            this.receiveMsgBox.Name = "receiveMsgBox";
            this.receiveMsgBox.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.Vertical;
            this.receiveMsgBox.Size = new System.Drawing.Size(479, 275);
            this.receiveMsgBox.TabIndex = 25;
            this.receiveMsgBox.Text = "";
            this.receiveMsgBox.TextChanged += new System.EventHandler(this.receiveMsgBox_TextChanged);
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.showCN);
            this.groupBox2.Controls.Add(this.receivedModeHex);
            this.groupBox2.Controls.Add(this.receiveMsgBox);
            this.groupBox2.Controls.Add(this.receivedModeStr);
            this.groupBox2.Controls.Add(this.clearReceiveMsgBoxBtn);
            this.groupBox2.Font = new System.Drawing.Font("黑体", 9.857143F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.groupBox2.Location = new System.Drawing.Point(325, 3);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(508, 350);
            this.groupBox2.TabIndex = 26;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "数据接收区";
            this.groupBox2.Enter += new System.EventHandler(this.groupBox2_Enter);
            // 
            // showCN
            // 
            this.showCN.AutoSize = true;
            this.showCN.Location = new System.Drawing.Point(14, 314);
            this.showCN.Name = "showCN";
            this.showCN.Size = new System.Drawing.Size(86, 18);
            this.showCN.TabIndex = 30;
            this.showCN.Text = "支持中文";
            this.showCN.UseVisualStyleBackColor = true;
            this.showCN.CheckedChanged += new System.EventHandler(this.showCN_CheckedChanged);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.timeSetMS);
            this.groupBox3.Controls.Add(this.timeSendMSg);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.sendMsgBox);
            this.groupBox3.Controls.Add(this.sendModeStr);
            this.groupBox3.Controls.Add(this.sendModeHex);
            this.groupBox3.Controls.Add(this.sendMsgBtn);
            this.groupBox3.Font = new System.Drawing.Font("黑体", 9.857143F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.groupBox3.Location = new System.Drawing.Point(13, 208);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(306, 145);
            this.groupBox3.TabIndex = 27;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "数据发送区";
            // 
            // timeSetMS
            // 
            this.timeSetMS.Location = new System.Drawing.Point(81, 104);
            this.timeSetMS.Name = "timeSetMS";
            this.timeSetMS.Size = new System.Drawing.Size(93, 22);
            this.timeSetMS.TabIndex = 29;
            this.timeSetMS.TextChanged += new System.EventHandler(this.timeSetMS_TextChanged);
            // 
            // timeSendMSg
            // 
            this.timeSendMSg.AutoSize = true;
            this.timeSendMSg.Location = new System.Drawing.Point(198, 73);
            this.timeSendMSg.Name = "timeSendMSg";
            this.timeSendMSg.Size = new System.Drawing.Size(86, 18);
            this.timeSendMSg.TabIndex = 28;
            this.timeSendMSg.Text = "自动发送";
            this.timeSendMSg.UseVisualStyleBackColor = true;
            this.timeSendMSg.CheckedChanged += new System.EventHandler(this.timeSendMSg_CheckedChanged);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(11, 107);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(69, 14);
            this.label6.TabIndex = 27;
            this.label6.Text = "间隔(ms)";
            // 
            // sendMsgBox
            // 
            this.sendMsgBox.Font = new System.Drawing.Font("微软雅黑", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.sendMsgBox.Location = new System.Drawing.Point(14, 22);
            this.sendMsgBox.Name = "sendMsgBox";
            this.sendMsgBox.ScrollBars = System.Windows.Forms.RichTextBoxScrollBars.Vertical;
            this.sendMsgBox.Size = new System.Drawing.Size(292, 42);
            this.sendMsgBox.TabIndex = 26;
            this.sendMsgBox.Text = "";
            this.sendMsgBox.TextChanged += new System.EventHandler(this.sendMsgBox_TextChanged_1);
            // 
            // sendModeStr
            // 
            this.sendModeStr.AutoSize = true;
            this.sendModeStr.Checked = true;
            this.sendModeStr.Location = new System.Drawing.Point(107, 73);
            this.sendModeStr.Name = "sendModeStr";
            this.sendModeStr.Size = new System.Drawing.Size(85, 18);
            this.sendModeStr.TabIndex = 24;
            this.sendModeStr.TabStop = true;
            this.sendModeStr.Text = "字符发送";
            this.sendModeStr.UseVisualStyleBackColor = true;
            this.sendModeStr.CheckedChanged += new System.EventHandler(this.sendModeStr_CheckedChanged);
            // 
            // sendModeHex
            // 
            this.sendModeHex.AutoSize = true;
            this.sendModeHex.Location = new System.Drawing.Point(14, 72);
            this.sendModeHex.Name = "sendModeHex";
            this.sendModeHex.Size = new System.Drawing.Size(87, 18);
            this.sendModeHex.TabIndex = 25;
            this.sendModeHex.Text = " HEX发送";
            this.sendModeHex.UseVisualStyleBackColor = true;
            this.sendModeHex.CheckedChanged += new System.EventHandler(this.sendModeHex_CheckedChanged);
            // 
            // timer1
            // 
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // 串口小程序
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(848, 365);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Font = new System.Drawing.Font("黑体", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            this.Margin = new System.Windows.Forms.Padding(4);
            this.Name = "串口小程序";
            this.RightToLeftLayout = true;
            this.Text = "串口小程序";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.ComboBox setPort;
        private System.Windows.Forms.ComboBox setBaundRate;
        private System.Windows.Forms.Button sendMsgBtn;
        private System.Windows.Forms.Button clearReceiveMsgBoxBtn;
        private System.Windows.Forms.Label 串口号;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.ComboBox setStopBits;
        private System.Windows.Forms.ComboBox setParity;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox setDataBits;
        private System.Windows.Forms.Button reloadPortBtn;
        private System.Windows.Forms.RadioButton receivedModeHex;
        private System.Windows.Forms.RadioButton receivedModeStr;
        private System.Windows.Forms.RichTextBox receiveMsgBox;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.RichTextBox sendMsgBox;
        private System.Windows.Forms.RadioButton sendModeStr;
        private System.Windows.Forms.RadioButton sendModeHex;
        private System.Windows.Forms.TextBox timeSetMS;
        private System.Windows.Forms.CheckBox timeSendMSg;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label serialStatus;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.CheckBox showCN;
        private System.Windows.Forms.Timer timer1;
    }
}

