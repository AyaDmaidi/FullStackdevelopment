using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace App42
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }


        private void Button_Clicked(object sender, EventArgs e)
        {
            int[] arr = new int[2030];
            for (int i= 1990;i <= 2030; i++)
            {
                label5.Text += i.ToString()+",";

            }
            
            
                
           


        }


    }
}
