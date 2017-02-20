<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true"   EnableEventValidation="false" CodeFile="Register.aspx.cs" Inherits="Account_Register" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
    <div class="container" style="margin-left:33%;margin-top:11%;">
    <div class="form-horizontal col-md-12">
        <h4>Create a new account.</h4>
        <hr />
    <div class="form-horizontal " >
    <asp:CreateUserWizard  ID="CreateUserWizard1" runat="server" ContinueDestinationPageUrl="~/BreakingNews.aspx" EmailLabelText="E-mail" UserNameLabelText="User Name" ValidatorTextStyle-CssClass="alert-danger" CreateUserButtonStyle-CssClass="btn btn-default" LabelStyle-CssClass="label-control" TextBoxStyle-CssClass="form-control" PasswordLabelText="Password" ConfirmPasswordLabelText="Confirm Password">
        <WizardSteps>
            <asp:CreateUserWizardStep Title="" ID="CreateUserWizardStep1" runat="server">
            </asp:CreateUserWizardStep>
            <asp:CompleteWizardStep ID="CompleteWizardStep1" runat="server">
            </asp:CompleteWizardStep>
        </WizardSteps>
    </asp:CreateUserWizard>
        </div>
        </div>
        </div>
</asp:Content>

