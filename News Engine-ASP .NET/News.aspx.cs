using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class News : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            if (Request.Params["id"] != null)
            {
                int id = int.Parse(Request.Params["id"]);
                id_stire.Text = Request.Params["id"];

                SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
                con.Open();

                SqlCommand get = con.CreateCommand();
                get.CommandText = "Select html,titlu From Stiri WHERE id=@id";
                get.Parameters.AddWithValue("@id", id);

                SqlDataReader values = get.ExecuteReader();
                while (values.Read())
                {
                    container.InnerHtml = values["html"].ToString();
                    titlu.InnerHtml = values["titlu"].ToString();
                }
            }
        }
        
    }

    protected void Button1_Click1(object sender, EventArgs e)
    {
        String text = TextArea1.InnerText;
        String name;

        if (User.Identity.IsAuthenticated)
        {
            name = User.Identity.Name;
        }
        else
        {
            TextBox textBox = (TextBox)LoginView1.FindControl("TextBox1");
            name = textBox.Text;
        }

        SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
        con.Open();

        SqlCommand set = con.CreateCommand();
        set.CommandText = "INSERT INTO Comments VALUES (@comentariu,@util,@data,@stire)";

        set.Parameters.AddWithValue("@comentariu", text);
        set.Parameters.AddWithValue("@util", name);
        set.Parameters.AddWithValue("@data", DateTime.Now);
        set.Parameters.AddWithValue("@stire", Request.Params["id"]);

        set.ExecuteNonQuery();

        ScriptManager.RegisterClientScriptBlock(this, this.GetType(), "alertMessage", "alert('Comentariul a fost adaugat!')", true);
        TextArea1.InnerText = "";
        if (!User.Identity.IsAuthenticated)
        {
            TextBox textBox = (TextBox)LoginView1.FindControl("TextBox1");
            textBox.Text = "";
        }
        con.Close();
        Response.Redirect("~/News.aspx?id=" + Request.Params["id"]);

    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        String id= Request.Params["id"]; 

        SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
        con.Open();

        SqlCommand delete = con.CreateCommand();
        delete.CommandText = "Delete FROM Stiri where Id=@id";

        delete.Parameters.AddWithValue("@id", id);

        delete.ExecuteNonQuery();

        con.Close();
        Response.Redirect("~/BreakingNews.aspx");
    }
}