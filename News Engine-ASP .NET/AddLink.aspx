<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="AddLink.aspx.cs" Inherits="AddLink" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

    <div class="container form-group">
        <div class="col-md-6">
            <asp:Label ID="Label1" Class="label-control" runat="server" Text="Title"></asp:Label>
            <asp:TextBox ID="Titlu" runat="server" CssClass="form-control"></asp:TextBox>
            <asp:Label ID="Label5" Class="label-control" runat="server" Text="Headline"></asp:Label>
            <asp:TextBox ID="head" runat="server" CssClass="form-control"></asp:TextBox>
            <asp:Label ID="Label2" Class="label-control" runat="server" Text="Link"></asp:Label>
            <asp:TextBox ID="link" runat="server" CssClass="form-control"></asp:TextBox>
            <asp:Label ID="Label6" Class="label-control" runat="server" Text="Add an image"></asp:Label>
            <asp:FileUpload ID="imagine" runat="server" />
            <br />
            <asp:Label ID="Label3" Class="label-control" runat="server" Text="Select category"></asp:Label>
            <asp:DropDownList ID="Categorie_lista" runat="server" DataSourceID="SqlDataSource1" DataTextField="Name" DataValueField="Id" CssClass="dropdown"></asp:DropDownList>
            <br/>
            <asp:Label ID="Label4" Class="label-control" runat="server" Text="Use a new category"></asp:Label>
            <asp:TextBox ID="Categorie_noua" runat="server" CssClass="form-control"></asp:TextBox>
        <br />
    <div>
        <asp:Button ID="Button1" runat="server" Text="Publish news" CssClass="btn btn-default" OnClick="Button1_Click" />
    </div>
     </div>
     </div>

</asp:Content>

