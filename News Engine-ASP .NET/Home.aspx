<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Home.aspx.cs"  EnableEventValidation="false" Inherits="_Default" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <h1 runat="server" id="h1" class="h1" style="margin-left:1%;">All news from category: </h1>
    <div class="container">
        <h4 style="display:inline-block;">Sort the news by: </h4>
        <asp:DropDownList ID="DropDownList1" runat="server">
            <asp:ListItem Value="data_adaugare" Selected="True">Apparition date</asp:ListItem>
            <asp:ListItem Value="titlu">Title</asp:ListItem>
        </asp:DropDownList>
        <asp:DropDownList ID="DropDownList2" runat="server">
            <asp:ListItem Value="ASC">Ascending</asp:ListItem>
            <asp:ListItem Value="DESC">Descending</asp:ListItem>
        </asp:DropDownList> 
        <asp:Button ID="Button1" runat="server" Text="Button" OnClick="Button1_Click" />
    </div>
    <asp:TextBox ID="TextBox1" runat="server" Visible="false"></asp:TextBox>
    <asp:TextBox ID="order" runat="server" Visible="false" Text="data_adaugare"></asp:TextBox>
    <asp:TextBox ID="ord" runat="server" Visible="false" Text="DESC"></asp:TextBox>
    <div runat="server" id="div">
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' SelectCommand="SELECT [titlu], [Id] FROM [Stiri] WHERE (([id_categorie] = @id_categorie) AND ([aprobat] = @aprobat))" EnableViewState="False">
            <SelectParameters>
                <asp:ControlParameter ControlID="TextBox1" PropertyName="Text" Name="id_categorie" Type="Int32"></asp:ControlParameter>
                <asp:Parameter DefaultValue="True" Name="aprobat" Type="Boolean"></asp:Parameter>
            </SelectParameters>
    </asp:SqlDataSource>
     <asp:Repeater runat="server" DataSourceID="SqlDataSource1" ID="repeater" EnableViewState="False">
        <ItemTemplate>
            <div class="row" style="width:30%;height:35%;display:inline-block;margin:1% 1%;align-content:center;" >
                <img style="width:95%;height:95%" id="imagine" class="rounded img-thumbnail" src="Images/<%# Eval("id")%>.jpeg"/>
                <h3 id="titlu" class="h3" style="text-align:center;">
                    <asp:HyperLink  runat="server" NavigateUrl='<%#"~/News.aspx?id=" + Eval("id")%>'> <%# Eval("titlu") %></asp:HyperLink>  
                </h3>
                
            </div>
        </ItemTemplate>
    </asp:Repeater>
    </div>


</asp:Content>

