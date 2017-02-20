using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Update : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            id.Text = Request.Params["id"];

            SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
            con.Open();

            SqlCommand sql = con.CreateCommand();
            sql.CommandText = "Select UserName from Users where userId=@id";
            sql.Parameters.AddWithValue("@id", id.Text);

            SqlDataReader reader = sql.ExecuteReader();
            while (reader.Read())
            {
                titlu.InnerText = "Update the role for user: " + reader["UserName"].ToString();
            }
            reader.Close();

            sql.CommandText = "Select ro.roleid from roles ro join usersinroles r on ro.roleid=r.roleid join  users u on u.userid=r.userid where u.userid=@userid";
            sql.Parameters.AddWithValue("@userid", id.Text);

           reader = sql.ExecuteReader();
            while (reader.Read())
            {
                DropDownList1.SelectedValue = reader["roleid"].ToString();
            }
            reader.Close();

            con.Close();
        }
    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        String id = Request.Params["id"];
        String rol = DropDownList1.SelectedValue;

        SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
        con.Open();

        SqlCommand sql = con.CreateCommand();
        sql.CommandText = "Update usersinroles set roleid=@rol where userid=@id";
        sql.Parameters.AddWithValue("@rol", rol);
        sql.Parameters.AddWithValue("@id", id);

        sql.ExecuteNonQuery();

        con.Close();

        Response.Redirect("~/AdministratorPanel.aspx");

    }

    protected void Button2_Click(object sender, EventArgs e)
    {
        Response.Redirect("~/AdministratorPanel.aspx");
    }
}