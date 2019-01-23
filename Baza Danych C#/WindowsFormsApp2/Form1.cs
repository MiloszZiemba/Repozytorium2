using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SQLite;


namespace WindowsFormsApp2
{
    public partial class Form1 : Form
    {
        SQLiteConnection m_dbConnection;

        public Form1()
        {
            InitializeComponent();
            //Create();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form2 form = new Form2();
            form.Show();

            
        }

        private void Create()
        {

            string sql = "CREATE TABLE Produkty ( id INTEGER PRIMARY KEY AUTOINCREMENT UNIQUE, nazwa varchar ( 20 ), cena int, ilosc int )";

            SQLiteCommand command = new SQLiteCommand(sql, m_dbConnection);

            command.ExecuteNonQuery();

            sql = "insert into Produkty (nazwa, cena, ilosc) values ('Pomidor', 3, 20)";
            command = new SQLiteCommand(sql, m_dbConnection);
            command.ExecuteNonQuery();

            sql = "insert into Produkty (nazwa, cena, ilosc) values ('Por', 6, 2)";
            command = new SQLiteCommand(sql, m_dbConnection);
            command.ExecuteNonQuery();

            sql = "insert into Produkty (nazwa, cena, ilosc) values ('Ziemniki', 800, 2)";
            command = new SQLiteCommand(sql, m_dbConnection);
            command.ExecuteNonQuery();
        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            
        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {
        }

        private void button2_Click(object sender, EventArgs e)
        {
            m_dbConnection =
                new SQLiteConnection("Data Source=Bazadanych.sqlite;Version=3;");
            m_dbConnection.Open();

            string sql = "insert into Produkty (nazwa, cena, ilosc) values ('"+ textBox7.Text.ToString() + "', " + numericUpDown1.Value+ ", " + numericUpDown2.Value + ")";
            SQLiteCommand command = new SQLiteCommand(sql, m_dbConnection);
            command.ExecuteNonQuery();

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {

        }

        private void button3_Click(object sender, EventArgs e)
        {
            m_dbConnection =
                new SQLiteConnection("Data Source=Bazadanych.sqlite;Version=3;");
            m_dbConnection.Open();

            string sql = "DELETE FROM Produkty WHERE id = " + numericUpDown3.Value;
            SQLiteCommand command = new SQLiteCommand(sql, m_dbConnection);
            command.ExecuteNonQuery();
        }
    }
}
