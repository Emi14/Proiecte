<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="Search.aspx.cs" Inherits="Search" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">
        
        <div class="container-fluid">
        <h1 class="h1">Search results for: <%=Request.Params["searchFor"] %></h1>
        
            <asp:TextBox ID="TextBox1" runat="server" Visible="false"></asp:TextBox>
        <div id="container" runat="server">
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' SelectCommand="SELECT [titlu], [data_adaugare], [Id] FROM [Stiri] WHERE ([titlu] LIKE '%' + @titlu + '%') ORDER BY [data_adaugare] DESC, [titlu]">
                <SelectParameters>
                    <asp:ControlParameter ControlID="TextBox1" PropertyName="Text" Name="titlu" Type="String"></asp:ControlParameter>
                </SelectParameters>
            </asp:SqlDataSource>
            <asp:Repeater runat="server" DataSourceID="SqlDataSource1">
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

        </div>
</asp:Content>

