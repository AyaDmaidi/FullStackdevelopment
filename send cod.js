
  function code(){
      let min = 100;
      let max = 900;
      let num = Math.floor(Math.random() * min) + max;
      return num;
  }

    function sendEmail() {
        emailS=  "rateeba-sawalha@hotmil.com";// document.getElementById(email);//_____________
      Email.send({
        Host: "smtp.gmail.com",
        Username: "cool_gang@bk.ru",
        Password: "#35sD0v!A_",
        To: emailS ,
        From: "cool_gang@bk.ru",
        Subject: "CODE to r",
        Body: "<html><h2>The code </h2><strong>num</strong><br></br><em>cope the code to the next step</em></html>",
      })
        .then(function (message) {
          console.log("mail sent successfully")
        });
    }

    code();
    sendEmail();
