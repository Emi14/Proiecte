<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Update.aspx.cs" Inherits="Update" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <asp:TextBox ID="id" runat="server" Visible="false"  ></asp:TextBox>
    
    

    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' SelectCommand="SELECT [RoleName], [RoleId] FROM [Roles]"></asp:SqlDataSource>
    <div class="col-md-6 ">
        <h1 id="titlu" runat="server" class="h1"></h1>
        <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="SqlDataSource1" DataTextField="RoleName" DataValueField="RoleId" CssClass="dropdown-toggle"></asp:DropDownList>
        <asp:Button ID="Button1" runat="server" Text="Update" OnClick="Button1_Click"/>
        <asp:Button ID="Button2" runat="server" Text="Cancel"  OnClick="Button2_Click"/>
    </div>
       
</asp:Content>

