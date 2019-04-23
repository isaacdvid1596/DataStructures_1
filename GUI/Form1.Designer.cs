namespace GUI
{
	partial class Form1
	{
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing)
		{
			if (disposing && (components != null))
			{
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.label1 = new System.Windows.Forms.Label();
			this.lblWidth = new System.Windows.Forms.Label();
			this.lblLength = new System.Windows.Forms.Label();
			this.lblPrice = new System.Windows.Forms.Label();
			this.lblRoomArea = new System.Windows.Forms.Label();
			this.lblCarpetingCost = new System.Windows.Forms.Label();
			this.btnArea = new System.Windows.Forms.Button();
			this.btnRoomCost = new System.Windows.Forms.Button();
			this.btnClear = new System.Windows.Forms.Button();
			this.txtWidth = new System.Windows.Forms.TextBox();
			this.txtLength = new System.Windows.Forms.TextBox();
			this.txtPrice = new System.Windows.Forms.TextBox();
			this.lblAreaResult = new System.Windows.Forms.Label();
			this.lblCarpetingResult = new System.Windows.Forms.Label();
			this.SuspendLayout();
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Font = new System.Drawing.Font("Algerian", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.label1.Location = new System.Drawing.Point(252, 18);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(273, 30);
			this.label1.TabIndex = 0;
			this.label1.Text = "My Carpeting Shop";
			this.label1.Click += new System.EventHandler(this.label1_Click);
			// 
			// lblWidth
			// 
			this.lblWidth.AutoSize = true;
			this.lblWidth.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblWidth.Location = new System.Drawing.Point(21, 92);
			this.lblWidth.Name = "lblWidth";
			this.lblWidth.Size = new System.Drawing.Size(96, 18);
			this.lblWidth.TabIndex = 1;
			this.lblWidth.Text = "Enter Width";
			// 
			// lblLength
			// 
			this.lblLength.AutoSize = true;
			this.lblLength.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblLength.Location = new System.Drawing.Point(21, 136);
			this.lblLength.Name = "lblLength";
			this.lblLength.Size = new System.Drawing.Size(103, 18);
			this.lblLength.TabIndex = 2;
			this.lblLength.Text = "Enter Length";
			this.lblLength.Click += new System.EventHandler(this.label3_Click);
			// 
			// lblPrice
			// 
			this.lblPrice.AutoSize = true;
			this.lblPrice.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblPrice.Location = new System.Drawing.Point(21, 179);
			this.lblPrice.Name = "lblPrice";
			this.lblPrice.Size = new System.Drawing.Size(129, 18);
			this.lblPrice.TabIndex = 3;
			this.lblPrice.Text = "Enter Price PSF";
			// 
			// lblRoomArea
			// 
			this.lblRoomArea.AutoSize = true;
			this.lblRoomArea.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblRoomArea.Location = new System.Drawing.Point(12, 340);
			this.lblRoomArea.Name = "lblRoomArea";
			this.lblRoomArea.Size = new System.Drawing.Size(93, 18);
			this.lblRoomArea.TabIndex = 4;
			this.lblRoomArea.Text = "Room Area";
			// 
			// lblCarpetingCost
			// 
			this.lblCarpetingCost.AutoSize = true;
			this.lblCarpetingCost.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblCarpetingCost.Location = new System.Drawing.Point(12, 394);
			this.lblCarpetingCost.Name = "lblCarpetingCost";
			this.lblCarpetingCost.Size = new System.Drawing.Size(172, 18);
			this.lblCarpetingCost.TabIndex = 5;
			this.lblCarpetingCost.Text = "Room Carpeting Cost";
			// 
			// btnArea
			// 
			this.btnArea.BackColor = System.Drawing.SystemColors.ActiveCaption;
			this.btnArea.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnArea.Location = new System.Drawing.Point(607, 58);
			this.btnArea.Name = "btnArea";
			this.btnArea.Size = new System.Drawing.Size(121, 52);
			this.btnArea.TabIndex = 6;
			this.btnArea.Text = "Area";
			this.btnArea.UseVisualStyleBackColor = false;
			this.btnArea.Click += new System.EventHandler(this.button1_Click);
			// 
			// btnRoomCost
			// 
			this.btnRoomCost.BackColor = System.Drawing.SystemColors.ActiveCaption;
			this.btnRoomCost.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnRoomCost.Location = new System.Drawing.Point(607, 133);
			this.btnRoomCost.Name = "btnRoomCost";
			this.btnRoomCost.Size = new System.Drawing.Size(121, 52);
			this.btnRoomCost.TabIndex = 7;
			this.btnRoomCost.Text = "Room Cost";
			this.btnRoomCost.UseVisualStyleBackColor = false;
			this.btnRoomCost.Click += new System.EventHandler(this.btnRoomCost_Click);
			// 
			// btnClear
			// 
			this.btnClear.BackColor = System.Drawing.SystemColors.ActiveCaption;
			this.btnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.btnClear.Location = new System.Drawing.Point(607, 210);
			this.btnClear.Name = "btnClear";
			this.btnClear.Size = new System.Drawing.Size(121, 52);
			this.btnClear.TabIndex = 8;
			this.btnClear.Text = "Clear";
			this.btnClear.UseVisualStyleBackColor = false;
			// 
			// txtWidth
			// 
			this.txtWidth.Location = new System.Drawing.Point(191, 90);
			this.txtWidth.Name = "txtWidth";
			this.txtWidth.Size = new System.Drawing.Size(114, 20);
			this.txtWidth.TabIndex = 9;
			// 
			// txtLength
			// 
			this.txtLength.Location = new System.Drawing.Point(191, 134);
			this.txtLength.Name = "txtLength";
			this.txtLength.Size = new System.Drawing.Size(114, 20);
			this.txtLength.TabIndex = 10;
			// 
			// txtPrice
			// 
			this.txtPrice.Location = new System.Drawing.Point(191, 177);
			this.txtPrice.Name = "txtPrice";
			this.txtPrice.Size = new System.Drawing.Size(114, 20);
			this.txtPrice.TabIndex = 11;
			// 
			// lblAreaResult
			// 
			this.lblAreaResult.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
			this.lblAreaResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblAreaResult.Location = new System.Drawing.Point(191, 329);
			this.lblAreaResult.Name = "lblAreaResult";
			this.lblAreaResult.Size = new System.Drawing.Size(114, 29);
			this.lblAreaResult.TabIndex = 12;
			this.lblAreaResult.Click += new System.EventHandler(this.lblAreaResult_Click);
			// 
			// lblCarpetingResult
			// 
			this.lblCarpetingResult.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
			this.lblCarpetingResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
			this.lblCarpetingResult.Location = new System.Drawing.Point(191, 383);
			this.lblCarpetingResult.Name = "lblCarpetingResult";
			this.lblCarpetingResult.Size = new System.Drawing.Size(114, 29);
			this.lblCarpetingResult.TabIndex = 13;
			this.lblCarpetingResult.Click += new System.EventHandler(this.lblCarpetingResult_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.BackColor = System.Drawing.SystemColors.ActiveBorder;
			this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
			this.ClientSize = new System.Drawing.Size(800, 450);
			this.Controls.Add(this.lblCarpetingResult);
			this.Controls.Add(this.lblAreaResult);
			this.Controls.Add(this.txtPrice);
			this.Controls.Add(this.txtLength);
			this.Controls.Add(this.txtWidth);
			this.Controls.Add(this.btnClear);
			this.Controls.Add(this.btnRoomCost);
			this.Controls.Add(this.btnArea);
			this.Controls.Add(this.lblCarpetingCost);
			this.Controls.Add(this.lblRoomArea);
			this.Controls.Add(this.lblPrice);
			this.Controls.Add(this.lblLength);
			this.Controls.Add(this.lblWidth);
			this.Controls.Add(this.label1);
			this.Name = "Form1";
			this.Text = "My First Form";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.Label lblWidth;
		private System.Windows.Forms.Label lblLength;
		private System.Windows.Forms.Label lblPrice;
		private System.Windows.Forms.Label lblRoomArea;
		private System.Windows.Forms.Label lblCarpetingCost;
		private System.Windows.Forms.Button btnArea;
		private System.Windows.Forms.Button btnRoomCost;
		private System.Windows.Forms.Button btnClear;
		private System.Windows.Forms.TextBox txtWidth;
		private System.Windows.Forms.TextBox txtLength;
		private System.Windows.Forms.TextBox txtPrice;
		private System.Windows.Forms.Label lblAreaResult;
		private System.Windows.Forms.Label lblCarpetingResult;
	}
}

