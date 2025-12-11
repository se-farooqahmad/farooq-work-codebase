<%@ Page Title="" Language="C#" MasterPageFile="~/MyMasterPage.Master" AutoEventWireup="true" CodeBehind="Search.aspx.cs" Inherits="MyWebSite.Search" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <asp:TextBox ID="TextBox1" runat="server" Width="247px"></asp:TextBox>&nbsp&nbsp
    <asp:Button ID="Button1" runat="server" Text="Search" Width="119px" OnClick="Search_Button_Click" />
    <br/> <br/>
    <div id="message" runat="server">
    </div>
    <br/>
    <asp:GridView ID="ItemGrid" runat="server" AutoGenerateColumns="False" OnRowDeleting="ItemGrid_RowDeleting" OnRowCancelingEdit="ItemGrid_RowCancelingEdit" OnRowEditing="ItemGrid_RowEditing" OnRowUpdating="ItemGrid_RowUpdating">
    <Columns>

            <asp:CommandField ShowEditButton="true" />
            <asp:CommandField ShowDeleteButton="true" />

            <asp:TemplateField HeaderText="ItemNo" HeaderStyle-HorizontalAlign="Left">
            <EditItemTemplate>
            <asp:Label ID="txtItemNo" runat="server" Text='<%# Bind("ItemNo") %>'></asp:Label>
            </EditItemTemplate>

            <ItemTemplate>
            <asp:Label ID="lblItemNo" runat="server" Text='<%# Bind("ItemNo") %>'></asp:Label>
            </ItemTemplate>

            <HeaderStyle HorizontalAlign="Left"></HeaderStyle>

            </asp:TemplateField>
            <asp:TemplateField HeaderText="ItemName" HeaderStyle-HorizontalAlign="Left">
	            <EditItemTemplate>
	            <asp:TextBox ID="txtItemName" runat="server" Text='<%# Bind("ItemName") %>'></asp:TextBox>
	            </EditItemTemplate>
	            <ItemTemplate>
	            <asp:Label ID="lblItemName" runat="server" Text='<%# Bind("ItemName") %>'></asp:Label>
	            </ItemTemplate>
	            <HeaderStyle HorizontalAlign="Left"></HeaderStyle>
            </asp:TemplateField>


            <asp:TemplateField HeaderText="TotalUnits" HeaderStyle-HorizontalAlign="Left">
	            <EditItemTemplate>
	            <asp:TextBox ID="txtTotalUnits"  runat="server" Text='<%# Bind("TotalUnits") %>'></asp:TextBox>
	            </EditItemTemplate>
	            <ItemTemplate>
	            <asp:Label ID="lblTotalUnits" runat="server" Text='<%# Bind("TotalUnits") %>'></asp:Label>
	            </ItemTemplate>
	            <HeaderStyle HorizontalAlign="Left"></HeaderStyle>
            </asp:TemplateField>

    </Columns>

    </asp:GridView>
</asp:Content>
