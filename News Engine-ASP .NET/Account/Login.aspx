<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Login.aspx.cs" Inherits="Account_Default"  EnableEventValidation="false"%>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">

</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
       <div class="container" style="margin-top:12%;margin-left:32%;">
        <div class="col-md-6">
            <section id="loginForm">
                <div class="form-horizontal">
                    <h4>Use a local account to log in.</h4>
                    <hr />
                    <asp:Login  ID="Login1" runat="server" PasswordLabelText="Password" UserNameLabelText="User Name" DestinationPageUrl="~/BreakingNews.aspx" LoginButtonStyle-CssClass="btn btn-default" LabelStyle-CssClass="col-md-6 control-label" TextBoxStyle-CssClass="form-control" CheckBoxStyle-CssClass="checkbox-inline" CreateUserText="Register if you don't have a local account." CreateUserUrl="~/Account/Register.aspx" BorderPadding="4" ValidatorTextStyle-CssClass="alert-danger" BorderStyle="None" TitleText=" "></asp:Login>
                    </div>
                </section>
            </div>
           </div>
</asp:Content>

