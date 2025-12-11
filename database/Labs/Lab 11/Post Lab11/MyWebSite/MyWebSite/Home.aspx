<%@ Page Title="" Language="C#" MasterPageFile="~/MyMasterPage.Master" AutoEventWireup="true" CodeBehind="Home.aspx.cs" Inherits="MyWebSite.Home" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    <asp:GridView ID="ItemGrid" runat="server" OnRowDeleting="ItemGrid_RowDeleting" AutoGenerateColumns="False" EnableViewState="False" OnRowCancelingEdit="ItemGrid_RowCancelingEdit" OnRowEditing="ItemGrid_RowEditing" OnRowUpdating="ItemGrid_RowUpdating">
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

    <br />

    Item Number: <asp:TextBox ID="TxtItmNo" runat="server"/>
    <br />
    Item Name: <asp:TextBox ID="TxtItmName" runat="server"/>
    <br />
    Total Units: <asp:TextBox ID="TxtUnits" runat="server"/>
    <br />
    <asp:Button ID="additem" runat="server" Text="submit" onclick="insrtItem_Click" />


</asp:Content>
