using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class MasterPage : System.Web.UI.MasterPage
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void LogoutButton_Click(object sender, EventArgs e)
    {
        FormsAuthentication.SignOut();
        Response.Redirect("~/BreakingNews.aspx");
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        String text = TextBox1.Text;

        Response.Redirect("~/Search.aspx?searchFor=" + text);
    }
}
