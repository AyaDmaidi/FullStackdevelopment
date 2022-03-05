let newpassword= document.getElementById(input2);
let user= document.getElementById(username);
var sql = `UPDATE users SET password=newpassword  WHERE username =user`;