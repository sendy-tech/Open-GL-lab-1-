namespace Контрольная_работа__Компьютерная_графика_
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.num1 = new System.Windows.Forms.TextBox();
            this.expand = new System.Windows.Forms.Button();
            this.narrow = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.Reflect = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // num1
            // 
            this.num1.Location = new System.Drawing.Point(133, 55);
            this.num1.Name = "num1";
            this.num1.Size = new System.Drawing.Size(71, 20);
            this.num1.TabIndex = 1;
            // 
            // expand
            // 
            this.expand.Location = new System.Drawing.Point(12, 37);
            this.expand.Name = "expand";
            this.expand.Size = new System.Drawing.Size(87, 23);
            this.expand.TabIndex = 3;
            this.expand.Text = "Расширить на";
            this.expand.UseVisualStyleBackColor = true;
            this.expand.Click += new System.EventHandler(this.expand_Click);
            // 
            // narrow
            // 
            this.narrow.Location = new System.Drawing.Point(12, 73);
            this.narrow.Name = "narrow";
            this.narrow.Size = new System.Drawing.Size(87, 23);
            this.narrow.TabIndex = 4;
            this.narrow.Text = "Сузить на";
            this.narrow.UseVisualStyleBackColor = true;
            this.narrow.Click += new System.EventHandler(this.narrow_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(210, 44);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(0, 13);
            this.label1.TabIndex = 5;
            // 
            // Reflect
            // 
            this.Reflect.AllowDrop = true;
            this.Reflect.Location = new System.Drawing.Point(218, 37);
            this.Reflect.Name = "Reflect";
            this.Reflect.Size = new System.Drawing.Size(75, 59);
            this.Reflect.TabIndex = 6;
            this.Reflect.Text = "Отразить";
            this.Reflect.UseVisualStyleBackColor = true;
            this.Reflect.Click += new System.EventHandler(this.Reflect_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.Reflect);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.narrow);
            this.Controls.Add(this.expand);
            this.Controls.Add(this.num1);
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.TextBox num1;
        private System.Windows.Forms.Button expand;
        private System.Windows.Forms.Button narrow;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button Reflect;
    }
}

