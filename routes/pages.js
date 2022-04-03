const express=require("express");
const authController = require('../controllers/auth');


const router=express.Router();

router.get('/', authController.isLoggedIn, (req, res) => {
    console.log("inside");
    console.log(req.user);
    res.render('index', {
      user: req.user
    });
  });
  
 







router.get('/',(req,res)=>{
    res.render('index');
});


router.get('/login', (req, res) => {
    res.render('login');
  });

router.get('/register',(req,res)=>{
    res.render('register');
});

router.get('/forgetpassword',(req,res)=>{
  res.render('forgetpassword');

  
  
});



router.get('/resetpassword',(req,res)=>{
  res.render('resetpassword');

  
  
});



module.exports=router;