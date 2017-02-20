<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="AddArticle.aspx.cs" Inherits="AddArticle" %>
<%@ Register Assembly="AjaxControlToolkit" Namespace="AjaxControlToolkit" TagPrefix="asp" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

    <div class="col-md-8 ">
    <asp:Label ID="Label1" Class="label-control" runat="server" Text="Title"></asp:Label>
    <asp:TextBox ID="Titlu" runat="server" CssClass="form-control"></asp:TextBox>
    <br />
    <asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
    <asp:TextBox ID="HTML" Rows="20" Columns="200" TextMode="MultiLine" runat="server" BorderStyle="Solid" BorderColor="#000099" BorderWidth="20px"></asp:TextBox>
    <asp:HtmlEditorExtender ID="HtmlEditorExtender1" EnableSanitization="false" TargetControlID="HTML" runat="server"></asp:HtmlEditorExtender>
     <br />
    <div class="col-md-6">
    <asp:Label ID="Label2" Class="label-control" runat="server" Text="Add an image"></asp:Label>
    <asp:FileUpload ID="imagine" runat="server" />

    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' SelectCommand="SELECT * FROM [Categories]"></asp:SqlDataSource>
     <asp:Label ID="Label3" Class="label-control" runat="server" Text="Select category"></asp:Label>
    <asp:DropDownList ID="Categorie_lista" runat="server" DataSourceID="SqlDataSource1" DataTextField="Name" DataValueField="Id" CssClass="dropdown"></asp:DropDownList>
    <br/>
    <asp:Label ID="Label4" Class="label-control" runat="server" Text="Use a new category"></asp:Label>
    <asp:TextBox ID="Categorie_noua" runat="server" CssClass="form-control"></asp:TextBox>
    </div>
        
        <div>
        <asp:Button ID="Button1" runat="server" Text="Publish news" CssClass="btn btn-default" OnClick="Button1_Click" />
        </div>
     </div>

</asp:Content>

