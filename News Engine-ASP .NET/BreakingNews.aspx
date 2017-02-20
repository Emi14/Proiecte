<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="BreakingNews.aspx.cs" Inherits="BreakingNews" %>

<asp:Content ID="Content1" ContentPlaceHolderID="head" Runat="Server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" Runat="Server">

    <div class="container-fluid">
        <div>
            <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' SelectCommand="SELECT [Id], [Name] FROM [Categories]"></asp:SqlDataSource>
                <asp:Repeater runat="server" DataSourceID="SqlDataSource3">
                <ItemTemplate >
                    
                    <hr class="divider"/>
                    <h2 class="h2"><%#Eval("name")%></h2>
                    <asp:TextBox Visible="false" ID="TextBox1" runat="server" Text='<%#Eval("id")%>'></asp:TextBox>
                    <asp:SqlDataSource ID="SqlDataSource4" runat="server" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' SelectCommand="SELECT [Id], [titlu] FROM [Stiri] WHERE (([id_categorie] = @id_categorie) AND ([aprobat] = @aprobat)) ORDER BY [data_adaugare] DESC">
                        <SelectParameters>
                            <asp:ControlParameter ControlID="TextBox1" PropertyName="Text" Name="id_categorie" Type="Int32"></asp:ControlParameter>
                            <asp:Parameter DefaultValue="True" Name="aprobat" Type="Boolean"></asp:Parameter>
                        </SelectParameters>
                    </asp:SqlDataSource>
                    <asp:Repeater runat="server" DataSourceID="SqlDataSource4">
                        <ItemTemplate>
                            <div class="row" style="width:30%;height:35%;display:inline-block;margin:1% 1%;align-content:center;" >
                                <img style="width:95%;height:95%" id="imagine" class="rounded img-thumbnail" src="Images/<%# Eval("id")%>.jpeg"/>
                                <h3 id="titlu" class="h3" style="text-align:center;">
                                    <asp:HyperLink  runat="server" NavigateUrl='<%#"~/News.aspx?id=" + Eval("id")%>'> <%# Eval("titlu") %></asp:HyperLink>  
                                </h3>
                            </div>
                        </ItemTemplate>
                    </asp:Repeater>
                </ItemTemplate>
            </asp:Repeater>
        </div>
    </div>
</asp:Content>

