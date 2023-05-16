//Initializes express server and imports necessary packages
const express = require('express');
const app = express();
const PORT = 3000; 

//required to read req json
app.use(express.urlencoded({ extended: true }));  

//basic GET request handler
app.get('/test',(req,res)=>{
    res.json({ok:true})
});

//basic POST request handler
app.post('/api/postdata',(req,res)=>{
    console.log(req.body.param1);
    res.sendStatus(200);
});


//Sets up server on port 3000
app.listen(PORT, ()=>{
    console.log('Server started');
});