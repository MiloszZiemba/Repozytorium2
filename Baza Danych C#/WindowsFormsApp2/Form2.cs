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
using System.Windows.Forms.DataVisualization.Charting;

namespace WindowsFormsApp2
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
            tableLayoutPanel1.RowCount = 1;
            SQLiteConnection m_dbConnection;
            m_dbConnection =
                new SQLiteConnection("Data Source=Bazadanych.sqlite;Version=3;");
            m_dbConnection.Open();
            string sql = "select * from Produkty order by id";
            SQLiteCommand command = new SQLiteCommand(sql, m_dbConnection);
            SQLiteDataReader reader = command.ExecuteReader();

            var series1 = new Series
            {
                Name = "Magazyn",
                IsVisibleInLegend = false,
                IsXValueIndexed = true,
                ChartType = SeriesChartType.Column
        };

            chart1.Series.Add(series1);


            while (reader.Read())
            {
                tableLayoutPanel1.RowCount = tableLayoutPanel1.RowCount + 1;
                tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.AutoSize));
                tableLayoutPanel1.Controls.Add(new Label { Text = reader["id"].ToString() }, 0, tableLayoutPanel1.RowCount - 1);
                tableLayoutPanel1.Controls.Add(new Label { Text = reader["nazwa"].ToString() }, 1, tableLayoutPanel1.RowCount - 1);
                tableLayoutPanel1.Controls.Add(new Label { Text = reader["cena"].ToString() }, 2, tableLayoutPanel1.RowCount - 1);
                tableLayoutPanel1.Controls.Add(new Label { Text = reader["ilosc"].ToString() }, 3, tableLayoutPanel1.RowCount - 1);

                chart1.Series[0].Points.AddXY(reader["nazwa"].ToString(), reader["ilosc"].ToString());

                Console.WriteLine("id: " + reader["id"] + "\tnazwa: " + reader["nazwa"] + "\tcena: " + reader["cena"] + "\tilosc: " + reader["ilosc"]);
            }

        }

        private void tableLayoutPanel1_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
