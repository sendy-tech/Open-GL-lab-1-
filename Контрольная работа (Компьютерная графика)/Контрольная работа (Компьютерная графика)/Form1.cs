using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Контрольная_работа__Компьютерная_графика_
{
    public partial class Form1 : Form
    {
        public int w, h;

        public Form1()
        {
            InitializeComponent();
            w = ClientSize.Width;
            h = ClientSize.Height;
            Point[] points =
                {
            new Point(w/2+60, h/2),
            new Point(w/2+30, h/2-50),
            new Point(w/2-30, h/2-50),
            new Point(w/2-60, h/2),
            new Point(w/2, h/2)
            };
            Draw(points);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
        }

        private void Draw(Point[] points)
        {
            Paint += (s, g) =>
            {
                g.Graphics.DrawPolygon(Pens.Red, points);
            };
        }

        private void ReDraw(Point[] points)
        {
            Graphics g = Graphics.FromHwnd(this.Handle);
            int w = ClientSize.Width;
            int h = ClientSize.Height;
            g.FillRectangle(Brushes.White, 0, 0, w, h);
            g.DrawPolygon(Pens.Red, points);
            g.Dispose();
        }

        private void expand_Click(object sender, EventArgs e)
        {
            int number = Convert.ToInt32(num1.Text);
            Point[] points =
                {
            new Point(w/2+60+number/2, h/2),
            new Point(w/2+30+number/2, h/2-50),
            new Point(w/2-30-number/2, h/2-50),
            new Point(w/2-60-number/2, h/2)
            };
            ReDraw(points);
        }

        private void narrow_Click(object sender, EventArgs e)
        {
            int number = Convert.ToInt32(num1.Text);
            Point[] points =
                {
            new Point(w/2+60-number/2, h/2),
            new Point(w/2+30-number/2, h/2-50),
            new Point(w/2-30+number/2, h/2-50),
            new Point(w/2-60+number/2, h/2)
            };
            ReDraw(points);
        }

        private void Reflect_Click(object sender, EventArgs e)
        {
            Point[] points =
                {
            new Point(w/2+60, h/2),
            new Point(w/2+30, h/2+50),
            new Point(w/2-30, h/2+50),
            new Point(w/2-60, h/2),
            new Point(w/2, h/2)
            };
            ReDraw(points);
        }
    }
}