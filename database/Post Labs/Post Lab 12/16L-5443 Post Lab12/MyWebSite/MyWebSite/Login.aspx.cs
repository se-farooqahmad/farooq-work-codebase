using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace MyWebSite
{
    public partial class Login : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void submit_Click(object sender, EventArgs e)
        {
            string username = txtusrname.Text.ToString();
            string password = txtpassword.Text.ToString();

            if ((username == "admin") && (password == "165443"))
            {
                Response.Redirect("Profile.aspx?Name=" + txtusrname.Text + "&pwd=" + txtpassword.Text);
            }
            else
            {
                Response.Write(@"<script langauge='text/javascript'>alert('Incorrect username or password');</script>");
            }
        }

    }
}