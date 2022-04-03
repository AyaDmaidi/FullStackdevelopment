const mysql=require("mysql");
const jwt=require('jsonwebtoken');
const bcrypt=require('bcryptjs');
const async = require("hbs/lib/async");
const { promisify } = require('util');
const express = require("express");
const dotenv=require("dotenv");



const db= mysql.createConnection({

    host: process.env.DATABASE_HOST,
    user: process.env.DATABASE_USER,
    password: process.env.DATABASE_PASSWORD,
    database: process.env.DATABASE

});



exports.register=(req,res)=>{
    console.log(req.body);

    


    const {name,email,password,passwordconfirm}=req.body;

db.query(' SELECT email FROM users WHERE email=?',[email],async(error,results)=>{
  if(error){
      console.log(error);
  }

  if(results.length>0){
      return res.render('register',{
          message:'That email is already in use'
      })
}

      else if (password !=passwordconfirm ){
          return res.render('register',{
              message:'password do not match'

      });
  
  }

let hashpassword=await bcrypt.hash(password,8);
console.log(hashpassword);

db.query('INSERT INTO  users SET ? ',{name:name,email:email,password:hashpassword},(error,results)=>{

if (error){
  console.log(error);

}
else{
  console.log(results);
  return res.render('register',{
      message:'User registered'

});

}

});

});


}







exports.login = async (req, res, next) => {
  const { email, password } = req.body;

  // 1) Check if email and password exist
  if (!email || !password) {
    return res.status(400).render("login", {
      message: 'Please provide email and password'
    });
  }

  // 2) Check if user exists && password is correct
  db.query('SELECT * FROM users WHERE email = ?', [email], async (error, results) => {
    console.log(results);
    console.log(password);
    const isMatch = await bcrypt.compare(password, results[0].password);
    console.log(isMatch);
    if(!results || !isMatch ) {
      return res.status(401).render("login", {
        message: 'Incorrect email or password'
      });
    } 
    else{
      return res.redirect('/');

      


    }

  
  });
};


// Only for rendered pages, no errors!
exports.isLoggedIn = async (req, res, next) => {
  console.log(req.cookies);
  if (req.cookies.jwt) {
    try {
      // 1) verify token
      const decoded = await promisify(jwt.verify)(
        req.cookies.jwt,
        process.env.JWT_SECRET
      );

      console.log("decoded");
      console.log(decoded);

      // 2) Check if user still exists
      db.query('SELECT * FROM users WHERE id = ?', [decoded.id], (error, result) => {
        console.log(result)
        if(!result) {
          return next();
        }
        // THERE IS A LOGGED IN USER
        req.user = result[0];
        // res.locals.user = result[0];
        console.log("next")
        return next();
      });
    } catch (err) {
      return next();
    }
  } else {
    next();
  }
};



exports.forgetpassword = async (req, res, next) => {
  const { email, password } = req.body;

  // 1) Check if email and password exist
  if ( !password) {
    return res.status(400).render("forgetpassword", {
      message: 'Please provide old  password'
    });
  }
  db.query('SELECT * FROM users WHERE email = ?', [email], async (error, results) => {
    console.log(results);
    console.log(password);
    const isMatch = await bcrypt.compare(password, results[0].password);
    console.log(isMatch);
    if(!results || !isMatch ) {
      return res.status(401).render("forgetpassword", {
        message: 'Incorrect email or password'
      });
    } 
    else{
      return res.redirect('/resetpassword');

      


    }

  
  });


  // 2) Check if user exists && password is correct

  




  }

  exports.resetpassword = async (req, res, next) => {
    const { email, password } = req.body;
  
    con.connect(function(err) {
      if (err) throw err;
      // if connection is successful
      con.query("UPDATE users SET password=password WHERE password=oldpassword", function (err, result, fields) {
        // if any error while executing above query, throw error
        if (err) throw err;
        // if there is no error, you have the result
        console.log(result);
      });
    });


    
  
     
     
    }








  
  
exports.logout = (req, res) => {
  res.cookie('jwt', 'loggedout', {
    expires: new Date(Date.now() + 10 * 1000),
    httpOnly: true
  });
  res.status(200).redirect("/");}
