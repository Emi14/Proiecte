using System;
using System.Collections.Generic;
using System.Data;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class BreakingNews : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {
       /* SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
        con.Open();

        SqlCommand get = con.CreateCommand();
        get.CommandText = "Select id,title From Stiri where id_categorie='1' ORDER by data_adaugare DESC";

        SqlDataAdapter data = new SqlDataAdapter(get);
        DataSet set = new DataSet();
        data.Fill(set);
        Repeater1.DataSource = set;
        Repeater1.DataBind();
    */    

    }
}