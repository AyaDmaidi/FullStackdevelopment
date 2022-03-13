var mysql = require('mysql');
var conn = mysql.createConnection({
  host: "127.0.0.1", //  host name
  user: "root",      //  database username
  password: "0592042401An",      //  database password
  database: "db" // database Name
}); 
 
conn.connect(function(err) {
  if (err) throw err;
  console.log('Database is connected successfully !');
});

module.exports = conn;

process.exit();

function Checksubscribed(){
    var username = new List<EmailParameter>
    username.Add(new EmailParameter() ,  Email = " youremail "  );

    var info = mc.GetMemberInfo( " listid " , username);
    var member = info.Data.SingleOrDefault();

    if (member.Status == "subscribed") {
        " email is subscribed "
    }
    else {
        " email is not subscribed "

    }
}


