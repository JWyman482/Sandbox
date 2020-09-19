var mysql = require('mysql');

var con = mysql.createConnection({
    host: "mydbinstance.cgnchvfak7nr.us-west-2.rds.amazonaws.com",
    user: "masterUsername",
    password: "masterUsername"
});

con.connect(function(err) {
    if (err) throw err;
    console.log("Connected!");
});