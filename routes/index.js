var express = require('express');
var router = express.Router();

router.use('/read', require('../routes/users')(router));

module.exports = router;

/*var express = require('express'); 
var router = express.Router();

router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express' });
});

module.exports = router;*/
