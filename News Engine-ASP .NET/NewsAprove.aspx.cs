using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class NewsAprove : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            if (Request.Params["id"] != null)
            {
                int id = int.Parse(Request.Params["id"]);
                

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

    protected void Button2_Click(object sender, EventArgs e)
    {
        int id = int.Parse(Request.Params["id"]);
        SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
        con.Open();

        SqlCommand get = con.CreateCommand();
        get.CommandText = "UPDATE Stiri SET aprobat='True' where id=@id";
        get.Parameters.AddWithValue("@id", id);

        get.ExecuteNonQuery();
        ScriptManager.RegisterClientScriptBlock(this, this.GetType(), "alertMessage", "alert('Stirea a fost aprobata cu succes!')", true);
        Response.Redirect("/BreakingNews.aspx");
    }
}