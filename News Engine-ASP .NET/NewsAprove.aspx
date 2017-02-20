<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="NewsAprove.aspx.cs" Inherits="NewsAprove" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
     <div class="container">
        <h1 id="titlu" runat="server" > </h1>
        <div  style="margin-left:20%;" >
         <img class="img-responsive" src="Images/<%= Request.Params["id"] %>.jpeg"  />
        </div>
        <div id="container" runat="server" class="jumbotron">
        
         
        </div>
         <asp:Button ID="Button2" runat="server" Text="Aprove this article" CssClass="btn btn-default" OnClick="Button2_Click" />
      </div>
</asp:Content>

