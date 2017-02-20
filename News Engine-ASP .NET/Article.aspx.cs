using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

public partial class Article : System.Web.UI.Page
{
    protected void Page_Load(object sender, EventArgs e)
    {

    }

    protected void Button1_Click(object sender, EventArgs e)
    {
        var titlu = Titlu.Text;
        int lista = int.Parse(Categorie_lista.SelectedValue);
        var categorie = Categorie_noua.Text;
        var html = HTML.Text;
        DateTime data = DateTime.Now;

        int id_categorie = 1;

        SqlConnection con = new SqlConnection(@"Data Source = (LocalDB)\MSSQLLocalDB; AttachDbFilename = C:\Users\emiio\OneDrive\Documente\Visual Studio 2015\WebSites\Stiri\App_Data\Database.mdf; Integrated Security = True");
        con.Open();

        SqlCommand getId = con.CreateCommand();

        if (categorie.ToString().Length != 0)
        {
            getId.CommandText = "INSERT INTO Categories (name) Values (@Name)";
            getId.Parameters.AddWithValue("@Name", categorie);
            getId.ExecuteNonQuery();

            getId.CommandText = "Select id From Categories Where Name=@nume";
            getId.Parameters.AddWithValue("@nume", categorie);
            SqlDataReader values = getId.ExecuteReader();

            while (values.Read())
            { id_categorie = values.GetInt32(0); }
            values.Close();

        }
        else { id_categorie = lista; }

        SqlCommand insert = con.CreateCommand();
        insert.CommandText = "INSERT INTO Stiri (titlu,id_categorie,data_adaugare,html,aprobat) VALUES (@Titlu,@Categorie,@Data,@Html,0)";
        insert.Parameters.AddWithValue("@Titlu", titlu);
        insert.Parameters.AddWithValue("@Categorie", id_categorie);
        insert.Parameters.AddWithValue("@Data", data);
        insert.Parameters.AddWithValue("@Html", html);

        insert.ExecuteNonQuery();

        getId.CommandText = "Select max(id) From stiri";

        SqlDataReader reader = getId.ExecuteReader();
        String ID = "1";
        while (reader.Read())
        {
            ID = reader.GetInt32(0).ToString();
        }
        reader.Close();

        con.Close();

        if (imagine.HasFile)
        {
            if (imagine.PostedFile.ContentType.ToLower().EndsWith("jpeg"))
            {
                imagine.SaveAs(Server.MapPath("~") + "/Images/" + ID + ".jpeg");
            }
        }

        ScriptManager.RegisterClientScriptBlock(this, this.GetType(), "alertMessage", "alert('Stirea a fost adaugata cu succes!')", true);
        Titlu.Text = "";
        HTML.Text = "";


    }

}