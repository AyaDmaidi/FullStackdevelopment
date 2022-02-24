using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;
using System.Windows;


namespace App41
{



   


    public partial class MainPage : ContentPage
    {

        public DateTime DateOfExpiration { get; set; }
        public MainPage()
        {
            InitializeComponent();

           
            var Url = "https://www.najah.edu/en/";
            Browser.Source = Url;
        }

        private void Button_Clicked_Google(object sender, EventArgs e)
        {
            var Url = "https://www.google.com/?hl=ar";
            Browser.Source = Url;
        }

        private void Button_Clicked_Zajel(object sender, EventArgs e)
        {


            var Url = "https://zajel.najah.edu/";
            Browser.Source = Url;

        }
    }
}

