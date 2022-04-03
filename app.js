const express = require("express");
const mysql=require("mysql");
const dotenv=require("dotenv");
const path=require('path');
const cookieParser = require('cookie-parser');
const app=express();

var createError = require('http-errors');
var flash = require('express-flash');
var session = require('express-session');
var bodyParser = require('body-parser');



dotenv.config({path:'./.env'})







const db= mysql.createConnection({

    host: process.env.DATABASE_HOST,
    user: process.env.DATABASE_USER,
    password: process.env.DATABASE_PASSWORD,
    database: process.env.DATABASE

});

// Parse URL-encoded bodies (as sent by HTML forms)
app.use(express.urlencoded({ extended: false }));
// Parse JSON bodies (as sent by API clients)
app.use(express.json());
app.use(cookieParser());

app.set('view engine','hbs');

const publicDirectory =path.join(__dirname,'../public')
app.use(express.static(publicDirectory));






db.connect((error)=>{

if (error){
    console.log(error);

}

else {
    console.log("Mysql connected");
}


});

// view engine setup
app.set('views', path.join(__dirname, 'views'));
 //Define Routes
app.use('/', require('./routes/pages'));
app.use('/auth', require('./routes/auth'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));
 
app.use(session({ 
    secret: '123458cat',
    resave: false,
    saveUninitialized: true,
    cookie: { maxAge: 60000 }
}))
 
app.use(flash());
 
//app.use('/', indexRouter);
 
// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
 
});
 
// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};
 
  // render the error page
  res.status(err.status || 500);
  res.render('error');
   
});





app.listen(5001, () => {
  console.log("listening on port 5000");
});



