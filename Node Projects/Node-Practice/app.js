var http = require('http');
var url = require('url');
var fs = require('fs');


http.createServer((req, res) => {
    fs.readFile('demo.html', function (err, data) {

        res.writeHead(200, { 'Content-Type': 'text/html' });       
        res.write(data);
        res.end();
    });
}).listen(1337);