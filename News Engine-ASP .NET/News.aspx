<%@ Page Title="" Language="C#" MasterPageFile="~/MasterPage.master" AutoEventWireup="true" CodeFile="News.aspx.cs" Inherits="News" %>

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
        <asp:TextBox Visible="false" ID="id_stire" runat="server"  ></asp:TextBox>
        <div runat="server" id="comments" class="container form-group">
            <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString='<%$ ConnectionStrings:DefaultConnection %>' SelectCommand="SELECT [text], [user], [date] FROM [Comments] WHERE ([id_stire] = @id_stire) ORDER BY [date], [user]">
                <SelectParameters>
                    <asp:ControlParameter ControlID="id_stire" PropertyName="Text" Name="id_stire" Type="Int32"></asp:ControlParameter>
                </SelectParameters>
            </asp:SqlDataSource>
           
            <div style="margin-bottom:5%;">
            <asp:Repeater ID="Repeater1" runat="server" DataSourceID="SqlDataSource1">
                <ItemTemplate>
                    <div class="col-md-8 caption" style="border:2px solid grey;margin-bottom:1%;">
                    <span><%# Eval("text") %></span>
                    <br />
                    <span>Written by <%# Eval("user")%> at <%#Eval("date") %> </span>
                    <br />
                    </div>
                </ItemTemplate>
            </asp:Repeater>
            <br />
            <br />
            </div>
           
            <hr  style="background-color:forestgreen;"/>
            <div class="carousel" style="margin-top:10%;">
            <asp:LoginView ID="LoginView1" runat="server">
                <AnonymousTemplate>
                    <asp:Label ID="Label1" runat="server" Text="Your name"></asp:Label> 
                     <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
                </AnonymousTemplate>
            </asp:LoginView>
            <textarea class="form-control" runat="server" id="TextArea1"  rows="5"></textarea>
            <asp:Button  CssClass="btn btn-default" ID="Button1" runat="server" Text="Add comment" OnClick="Button1_Click1" />
        </div>
            <br />
            <br />

            <asp:LoginView ID="LoginView2" runat="server">
                <RoleGroups>
                <asp:RoleGroup Roles="Editor" >
                <ContentTemplate>

                    <asp:Button ID="Button2" runat="server" Text="Delete news" CssClass="btn btn-danger" OnClick="Button2_Click"/>
                </ContentTemplate>
                </asp:RoleGroup>
                    </RoleGroups>
            </asp:LoginView>
        </div>
    </div>
</asp:Content>

