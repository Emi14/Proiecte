<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="AdministratorPanel.aspx.cs" Inherits="AdministratorPanel"  EnableEventValidation="false"%>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConflictDetection="CompareAllValues" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' OldValuesParameterFormatString="original_{0}" SelectCommand="SELECT Users.UserName, Users.UserId, Roles.RoleName FROM Users LEFT OUTER JOIN UsersInRoles ON Users.UserId = UsersInRoles.UserId LEFT OUTER JOIN Roles ON UsersInRoles.RoleId = Roles.RoleId ORDER BY Roles.RoleName desc">
    </asp:SqlDataSource>
    <div class="container">
    <h1 class="h1">Manage Roles</h1>
    <div class="table-responsive">
    <asp:GridView ID="GridView1" runat="server" AutoGenerateColumns="False" BackColor="White" BorderColor="#CCCCCC" BorderStyle="None" BorderWidth="1px" CellPadding="4" ForeColor="Black" GridLines="Horizontal" DataKeyNames="UserId" DataSourceID="SqlDataSource1" CssClass="table">
        <Columns>
            <asp:BoundField DataField="UserName" HeaderText="User Name" SortExpression="UserName"></asp:BoundField>
            <asp:BoundField DataField="RoleName" HeaderText="Role Name" SortExpression="RoleName"></asp:BoundField>
            <asp:HyperLinkField  HeaderText="Update role" Text="Update" DataNavigateUrlFields="Userid" DataNavigateUrlFormatString="~/Update.aspx?id={0}"/>
        </Columns>

        <FooterStyle BackColor="#CCCC99" ForeColor="Black"></FooterStyle>

        <HeaderStyle BackColor="#333333" Font-Bold="True" ForeColor="White"></HeaderStyle>

        <PagerStyle HorizontalAlign="Right" BackColor="White" ForeColor="Black"></PagerStyle>

        <SelectedRowStyle BackColor="#CC3333" Font-Bold="True" ForeColor="White"></SelectedRowStyle>

        <SortedAscendingCellStyle BackColor="#F7F7F7"></SortedAscendingCellStyle>

        <SortedAscendingHeaderStyle BackColor="#4B4B4B"></SortedAscendingHeaderStyle>

        <SortedDescendingCellStyle BackColor="#E5E5E5"></SortedDescendingCellStyle>

        <SortedDescendingHeaderStyle BackColor="#242121"></SortedDescendingHeaderStyle>
    </asp:GridView>

        <asp:Repeater ID="Repeater1" runat="server">

        </asp:Repeater>

    </div>
        </div>

   
  
</asp:Content>

