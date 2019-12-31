namespace CircularElevator
{
    partial class MainForm
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.floorSelectionPanel = new System.Windows.Forms.Panel();
            this.cF6Btn = new System.Windows.Forms.Panel();
            this.cF5Btn = new System.Windows.Forms.Panel();
            this.cF4Btn = new System.Windows.Forms.Panel();
            this.cF3Btn = new System.Windows.Forms.Panel();
            this.cF2Btn = new System.Windows.Forms.Panel();
            this.cF1Btn = new System.Windows.Forms.Panel();
            this.rootPanel = new System.Windows.Forms.Panel();
            this.controlPanel = new System.Windows.Forms.Panel();
            this.downLed = new System.Windows.Forms.Panel();
            this.upLed = new System.Windows.Forms.Panel();
            this.panel7 = new System.Windows.Forms.Panel();
            this.extimatedLabel = new System.Windows.Forms.Label();
            this.estimatedTimeLabel = new System.Windows.Forms.Label();
            this.f3Btn = new System.Windows.Forms.Panel();
            this.f4Btn = new System.Windows.Forms.Panel();
            this.f2Btn = new System.Windows.Forms.Panel();
            this.f5Btn = new System.Windows.Forms.Panel();
            this.f1Btn = new System.Windows.Forms.Panel();
            this.f6Btn = new System.Windows.Forms.Panel();
            this.simulationView = new System.Windows.Forms.PictureBox();
            this.floorSelectionPanel.SuspendLayout();
            this.rootPanel.SuspendLayout();
            this.controlPanel.SuspendLayout();
            this.panel7.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.simulationView)).BeginInit();
            this.SuspendLayout();
            // 
            // floorSelectionPanel
            // 
            this.floorSelectionPanel.Controls.Add(this.cF6Btn);
            this.floorSelectionPanel.Controls.Add(this.cF5Btn);
            this.floorSelectionPanel.Controls.Add(this.cF4Btn);
            this.floorSelectionPanel.Controls.Add(this.cF3Btn);
            this.floorSelectionPanel.Controls.Add(this.cF2Btn);
            this.floorSelectionPanel.Controls.Add(this.cF1Btn);
            this.floorSelectionPanel.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.floorSelectionPanel.Location = new System.Drawing.Point(600, 523);
            this.floorSelectionPanel.Name = "floorSelectionPanel";
            this.floorSelectionPanel.Size = new System.Drawing.Size(500, 77);
            this.floorSelectionPanel.TabIndex = 2;
            // 
            // cF6Btn
            // 
            this.cF6Btn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("cF6Btn.BackgroundImage")));
            this.cF6Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.cF6Btn.Font = new System.Drawing.Font("맑은 고딕", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cF6Btn.Location = new System.Drawing.Point(386, 8);
            this.cF6Btn.Name = "cF6Btn";
            this.cF6Btn.Size = new System.Drawing.Size(60, 59);
            this.cF6Btn.TabIndex = 3;
            this.cF6Btn.Click += new System.EventHandler(this.CommonFloorButton_Click);
            // 
            // cF5Btn
            // 
            this.cF5Btn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("cF5Btn.BackgroundImage")));
            this.cF5Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.cF5Btn.Font = new System.Drawing.Font("맑은 고딕", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cF5Btn.Location = new System.Drawing.Point(311, 8);
            this.cF5Btn.Name = "cF5Btn";
            this.cF5Btn.Size = new System.Drawing.Size(60, 59);
            this.cF5Btn.TabIndex = 3;
            this.cF5Btn.Click += new System.EventHandler(this.CommonFloorButton_Click);
            // 
            // cF4Btn
            // 
            this.cF4Btn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("cF4Btn.BackgroundImage")));
            this.cF4Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.cF4Btn.Font = new System.Drawing.Font("맑은 고딕", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cF4Btn.Location = new System.Drawing.Point(235, 8);
            this.cF4Btn.Name = "cF4Btn";
            this.cF4Btn.Size = new System.Drawing.Size(60, 59);
            this.cF4Btn.TabIndex = 3;
            this.cF4Btn.Click += new System.EventHandler(this.CommonFloorButton_Click);
            // 
            // cF3Btn
            // 
            this.cF3Btn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("cF3Btn.BackgroundImage")));
            this.cF3Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.cF3Btn.Font = new System.Drawing.Font("맑은 고딕", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cF3Btn.Location = new System.Drawing.Point(160, 8);
            this.cF3Btn.Name = "cF3Btn";
            this.cF3Btn.Size = new System.Drawing.Size(60, 59);
            this.cF3Btn.TabIndex = 3;
            this.cF3Btn.Click += new System.EventHandler(this.CommonFloorButton_Click);
            // 
            // cF2Btn
            // 
            this.cF2Btn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("cF2Btn.BackgroundImage")));
            this.cF2Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.cF2Btn.Font = new System.Drawing.Font("맑은 고딕", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cF2Btn.Location = new System.Drawing.Point(84, 8);
            this.cF2Btn.Name = "cF2Btn";
            this.cF2Btn.Size = new System.Drawing.Size(60, 59);
            this.cF2Btn.TabIndex = 3;
            this.cF2Btn.Click += new System.EventHandler(this.CommonFloorButton_Click);
            // 
            // cF1Btn
            // 
            this.cF1Btn.BackgroundImage = ((System.Drawing.Image)(resources.GetObject("cF1Btn.BackgroundImage")));
            this.cF1Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.cF1Btn.Font = new System.Drawing.Font("맑은 고딕", 27.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.cF1Btn.Location = new System.Drawing.Point(9, 8);
            this.cF1Btn.Name = "cF1Btn";
            this.cF1Btn.Size = new System.Drawing.Size(60, 59);
            this.cF1Btn.TabIndex = 3;
            this.cF1Btn.Click += new System.EventHandler(this.CommonFloorButton_Click);
            // 
            // rootPanel
            // 
            this.rootPanel.Controls.Add(this.controlPanel);
            this.rootPanel.Controls.Add(this.floorSelectionPanel);
            this.rootPanel.Controls.Add(this.simulationView);
            this.rootPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.rootPanel.Font = new System.Drawing.Font("맑은 고딕", 11F);
            this.rootPanel.Location = new System.Drawing.Point(0, 0);
            this.rootPanel.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.rootPanel.Name = "rootPanel";
            this.rootPanel.Size = new System.Drawing.Size(1100, 600);
            this.rootPanel.TabIndex = 0;
            // 
            // controlPanel
            // 
            this.controlPanel.BackgroundImage = global::CircularElevator.Properties.Resources.guide1;
            this.controlPanel.Controls.Add(this.downLed);
            this.controlPanel.Controls.Add(this.upLed);
            this.controlPanel.Controls.Add(this.panel7);
            this.controlPanel.Controls.Add(this.f3Btn);
            this.controlPanel.Controls.Add(this.f4Btn);
            this.controlPanel.Controls.Add(this.f2Btn);
            this.controlPanel.Controls.Add(this.f5Btn);
            this.controlPanel.Controls.Add(this.f1Btn);
            this.controlPanel.Controls.Add(this.f6Btn);
            this.controlPanel.Dock = System.Windows.Forms.DockStyle.Fill;
            this.controlPanel.Location = new System.Drawing.Point(600, 0);
            this.controlPanel.Name = "controlPanel";
            this.controlPanel.Size = new System.Drawing.Size(500, 523);
            this.controlPanel.TabIndex = 6;
            // 
            // downLed
            // 
            this.downLed.Location = new System.Drawing.Point(281, 321);
            this.downLed.Name = "downLed";
            this.downLed.Size = new System.Drawing.Size(90, 90);
            this.downLed.TabIndex = 5;
            this.downLed.Paint += new System.Windows.Forms.PaintEventHandler(this.DirectionLed_Paint);
            // 
            // upLed
            // 
            this.upLed.Location = new System.Drawing.Point(281, 225);
            this.upLed.Name = "upLed";
            this.upLed.Size = new System.Drawing.Size(90, 90);
            this.upLed.TabIndex = 5;
            this.upLed.Paint += new System.Windows.Forms.PaintEventHandler(this.DirectionLed_Paint);
            // 
            // panel7
            // 
            this.panel7.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(64)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.panel7.Controls.Add(this.extimatedLabel);
            this.panel7.Controls.Add(this.estimatedTimeLabel);
            this.panel7.Location = new System.Drawing.Point(36, 35);
            this.panel7.Name = "panel7";
            this.panel7.Size = new System.Drawing.Size(353, 85);
            this.panel7.TabIndex = 4;
            // 
            // extimatedLabel
            // 
            this.extimatedLabel.AutoSize = true;
            this.extimatedLabel.BackColor = System.Drawing.Color.Transparent;
            this.extimatedLabel.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.extimatedLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.extimatedLabel.Location = new System.Drawing.Point(15, 7);
            this.extimatedLabel.Name = "extimatedLabel";
            this.extimatedLabel.Size = new System.Drawing.Size(252, 28);
            this.extimatedLabel.TabIndex = 0;
            this.extimatedLabel.Text = "Estimated time remaining:";
            // 
            // estimatedTimeLabel
            // 
            this.estimatedTimeLabel.AutoSize = true;
            this.estimatedTimeLabel.Font = new System.Drawing.Font("맑은 고딕", 21.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.estimatedTimeLabel.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(192)))), ((int)(((byte)(0)))), ((int)(((byte)(0)))));
            this.estimatedTimeLabel.Location = new System.Drawing.Point(13, 35);
            this.estimatedTimeLabel.Name = "estimatedTimeLabel";
            this.estimatedTimeLabel.Size = new System.Drawing.Size(93, 40);
            this.estimatedTimeLabel.TabIndex = 0;
            this.estimatedTimeLabel.Text = "00:00";
            // 
            // f3Btn
            // 
            this.f3Btn.BackgroundImage = global::CircularElevator.Properties.Resources.unselectedFloorBtn;
            this.f3Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.f3Btn.Font = new System.Drawing.Font("맑은 고딕", 30F, System.Drawing.FontStyle.Bold);
            this.f3Btn.Location = new System.Drawing.Point(41, 148);
            this.f3Btn.Name = "f3Btn";
            this.f3Btn.Size = new System.Drawing.Size(90, 90);
            this.f3Btn.TabIndex = 3;
            this.f3Btn.Click += new System.EventHandler(this.CallingFloorButton_Click);
            // 
            // f4Btn
            // 
            this.f4Btn.BackgroundImage = global::CircularElevator.Properties.Resources.unselectedFloorBtn;
            this.f4Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.f4Btn.Font = new System.Drawing.Font("맑은 고딕", 30F, System.Drawing.FontStyle.Bold);
            this.f4Btn.Location = new System.Drawing.Point(158, 387);
            this.f4Btn.Name = "f4Btn";
            this.f4Btn.Size = new System.Drawing.Size(90, 90);
            this.f4Btn.TabIndex = 3;
            this.f4Btn.Click += new System.EventHandler(this.CallingFloorButton_Click);
            // 
            // f2Btn
            // 
            this.f2Btn.BackgroundImage = global::CircularElevator.Properties.Resources.unselectedFloorBtn;
            this.f2Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.f2Btn.Font = new System.Drawing.Font("맑은 고딕", 30F, System.Drawing.FontStyle.Bold);
            this.f2Btn.Location = new System.Drawing.Point(41, 265);
            this.f2Btn.Name = "f2Btn";
            this.f2Btn.Size = new System.Drawing.Size(90, 90);
            this.f2Btn.TabIndex = 3;
            this.f2Btn.Click += new System.EventHandler(this.CallingFloorButton_Click);
            // 
            // f5Btn
            // 
            this.f5Btn.BackgroundImage = global::CircularElevator.Properties.Resources.unselectedFloorBtn;
            this.f5Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.f5Btn.Font = new System.Drawing.Font("맑은 고딕", 30F, System.Drawing.FontStyle.Bold);
            this.f5Btn.Location = new System.Drawing.Point(158, 265);
            this.f5Btn.Name = "f5Btn";
            this.f5Btn.Size = new System.Drawing.Size(90, 90);
            this.f5Btn.TabIndex = 3;
            this.f5Btn.Click += new System.EventHandler(this.CallingFloorButton_Click);
            // 
            // f1Btn
            // 
            this.f1Btn.BackgroundImage = global::CircularElevator.Properties.Resources.unselectedFloorBtn;
            this.f1Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.f1Btn.Font = new System.Drawing.Font("맑은 고딕", 30F, System.Drawing.FontStyle.Bold);
            this.f1Btn.Location = new System.Drawing.Point(41, 387);
            this.f1Btn.Name = "f1Btn";
            this.f1Btn.Size = new System.Drawing.Size(90, 90);
            this.f1Btn.TabIndex = 3;
            this.f1Btn.Click += new System.EventHandler(this.CallingFloorButton_Click);
            // 
            // f6Btn
            // 
            this.f6Btn.BackgroundImage = global::CircularElevator.Properties.Resources.unselectedFloorBtn;
            this.f6Btn.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Zoom;
            this.f6Btn.Font = new System.Drawing.Font("맑은 고딕", 30F, System.Drawing.FontStyle.Bold);
            this.f6Btn.Location = new System.Drawing.Point(158, 148);
            this.f6Btn.Name = "f6Btn";
            this.f6Btn.Size = new System.Drawing.Size(90, 90);
            this.f6Btn.TabIndex = 3;
            this.f6Btn.Click += new System.EventHandler(this.CallingFloorButton_Click);
            // 
            // simulationView
            // 
            this.simulationView.Dock = System.Windows.Forms.DockStyle.Left;
            this.simulationView.Image = global::CircularElevator.Properties.Resources.background;
            this.simulationView.Location = new System.Drawing.Point(0, 0);
            this.simulationView.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.simulationView.Name = "simulationView";
            this.simulationView.Size = new System.Drawing.Size(600, 600);
            this.simulationView.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.simulationView.TabIndex = 1;
            this.simulationView.TabStop = false;
            this.simulationView.Paint += new System.Windows.Forms.PaintEventHandler(this.SimulationView_Paint);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 20F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.White;
            this.ClientSize = new System.Drawing.Size(1100, 600);
            this.Controls.Add(this.rootPanel);
            this.Font = new System.Drawing.Font("맑은 고딕", 11F);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Margin = new System.Windows.Forms.Padding(4, 5, 4, 5);
            this.MaximizeBox = false;
            this.Name = "MainForm";
            this.Text = "Elevator Simulator";
            this.floorSelectionPanel.ResumeLayout(false);
            this.rootPanel.ResumeLayout(false);
            this.controlPanel.ResumeLayout(false);
            this.panel7.ResumeLayout(false);
            this.panel7.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.simulationView)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.PictureBox simulationView;
        private System.Windows.Forms.Panel floorSelectionPanel;
        private System.Windows.Forms.Panel cF6Btn;
        private System.Windows.Forms.Panel cF5Btn;
        private System.Windows.Forms.Panel cF4Btn;
        private System.Windows.Forms.Panel cF3Btn;
        private System.Windows.Forms.Panel cF2Btn;
        private System.Windows.Forms.Panel cF1Btn;
        private System.Windows.Forms.Panel f3Btn;
        private System.Windows.Forms.Panel f2Btn;
        private System.Windows.Forms.Panel f1Btn;
        private System.Windows.Forms.Panel f6Btn;
        private System.Windows.Forms.Panel f5Btn;
        private System.Windows.Forms.Panel f4Btn;
        private System.Windows.Forms.Panel panel7;
        private System.Windows.Forms.Label estimatedTimeLabel;
        private System.Windows.Forms.Panel rootPanel;
        private System.Windows.Forms.Label extimatedLabel;
        private System.Windows.Forms.Panel controlPanel;
        private System.Windows.Forms.Panel downLed;
        private System.Windows.Forms.Panel upLed;
    }
}

