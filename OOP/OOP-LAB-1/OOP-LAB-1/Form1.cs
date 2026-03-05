namespace OOP_LAB_1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }


        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            double num1 =
                Convert.ToDouble(textBox1.Text);
            double num2 =
        Convert.ToDouble(textBox2.Text);

            double answer = num1 + num2;
            label3.Text = "+";

            label1.Text = answer.ToString();
            if (answer > 0)
            {
                label1.BackColor = Color.Blue;
            }
            else
            {
                label1.BackColor = Color.Pink;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            double num1 =
    Convert.ToDouble(textBox1.Text);
            double num2 =
        Convert.ToDouble(textBox2.Text);

            double answer = num1 - num2;
            label3.Text = "-";
            label1.Text = answer.ToString();
            if (answer > 0)
            {
                label1.BackColor = Color.Blue;
            }
            else
            {
                label1.BackColor = Color.Pink;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            double num1 =
    Convert.ToDouble(textBox1.Text);
            double num2 =
        Convert.ToDouble(textBox2.Text);

            double answer = num1 * num2;
            label3.Text = "*";
            label1.Text = answer.ToString();
            if (answer > 0)
            {
                label1.BackColor = Color.Blue;
            }
            else
            {
                label1.BackColor = Color.Pink;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            double num1 =
    Convert.ToDouble(textBox1.Text);
            double num2 =
        Convert.ToDouble(textBox2.Text);

            double answer = num1 / num2;
            label3.Text = "/";
            label1.Text = answer.ToString();
            if (answer > 0)
            {
                label1.BackColor = Color.Blue;
            }
            else
            {
                label1.BackColor = Color.Pink;
            }
        }

        private void button1_MouseEnter(object sender, EventArgs e)
        {
            button1.ForeColor = Color.Red;
        }

        private void button1_MouseLeave(object sender, EventArgs e)
        {
            button1.ForeColor = Color.Black;
        }

        private void button2_MouseEnter(object sender, EventArgs e)
        {
            button2.ForeColor = Color.Red;
        }

        private void button2_MouseLeave(object sender, EventArgs e)
        {
            button2.ForeColor = Color.Black;
        }
        private void button3_MouseEnter(object sender, EventArgs e)
        {
            button3.ForeColor = Color.Red;
        }

        private void button3_MouseLeave(object sender, EventArgs e)
        {
            button3.ForeColor = Color.Black;
        }
        private void button4_MouseEnter(object sender, EventArgs e)
        {
            button4.ForeColor = Color.Red;
        }

        private void button4_MouseLeave(object sender, EventArgs e)
        {
            button4.ForeColor = Color.Black;
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}