using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class _Default : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack)
        {
            String id = Request.Params["category"];
            TextBox1.Text = id;
               

            SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
            con.Open();

            SqlCommand get = con.CreateCommand();
            get.CommandText = "Select name from Categories where Id=@id";
            get.Parameters.AddWithValue("@id", id);

            SqlDataReader values = get.ExecuteReader();

            String nume="";

            while (values.Read())
            {
                nume = values["name"].ToString();
            }

            h1.InnerText = h1.InnerText + nume;
        }
    }
    protected void Button1_Click(object sender, EventArgs e)
    {
        String id = Request.Params["category"];
        String atribut = DropDownList1.SelectedValue;
        String ordine = DropDownList2.SelectedValue;

        order.Text = atribut;
        ord.Text = ordine;

        SqlDataSource sql = (SqlDataSource) div.FindControl("SqlDataSource1");
        sql.SelectCommand = "SELECT [titlu],[Id] FROM[Stiri] WHERE([id_categorie] =@id_categorie)  ORDER BY [" + atribut + "] " + ordine;
        sql.DataBind();
        
        
        repeater.DataBind();
        
       

    }
}