<%@ Page Title="" Language="C#" MasterPageFile="~/MyMasterPage.Master" AutoEventWireup="true" CodeBehind="Login.aspx.cs" Inherits="MyWebSite.Login" %>
<asp:Content ID="Content1" ContentPlaceHolderID="head" runat="server">
</asp:Content>
<asp:Content ID="Content2" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
    User: 
    <asp:TextBox ID="txtusrname" runat="server"></asp:TextBox>
    <br/>
       Password:  <asp:TextBox ID="txtpassword" runat="server" TextMode="Password"></asp:TextBox>
    <br/>
    <asp:Button ID="submit" runat="server" Text="submit" onclick="submit_Click" OnClientClick= "javascript: return validation(); " />
    <script type="text/javascript">
        function validation() {
            var username = document.getElementById('<%=txtusrname.ClientID %>').value;
            var password = document.getElementById('<%=txtpassword.ClientID %>').value;



            if (username.search("'") >= 0 || username.search("--") >= 0) // sql injection characters
            {
                alert('Please Enter Username');
                return false;


            }
            else {
                if (password.search("'") >= 0 || password.search("--") >= 0) {
                    alert('Please Enter Password');


                    return false;
                }
                return true;
            }

        }
    </script>

</asp:Content>
