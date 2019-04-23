using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace GUI
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void label1_Click(object sender, EventArgs e)
		{

		}

		private void button1_Click(object sender, EventArgs e)
		{
			int length, width, area;

			width = Convert.ToInt32(txtWidth.Text);

			length = Convert.ToInt32(txtLength.Text);

			area = length * width;

			lblAreaResult.Text = area.ToString("n");

		}

		private void label3_Click(object sender, EventArgs e)
		{

		}

		private void lblAreaResult_Click(object sender, EventArgs e)
		{

		}

		private void lblCarpetingResult_Click(object sender, EventArgs e)
		{

		}

		private void btnRoomCost_Click(object sender, EventArgs e)
		{
			int width, length;

			double price, roomCost;


			width = Convert.ToInt32(txtWidth.Text);

			length = Convert.ToInt32(txtLength.Text);

			price = Convert.ToDouble(txtPrice.Text);


			roomCost = width * length * price;

			lblCarpetingResult.Text = roomCost.ToString("c");

		}
	}
}
