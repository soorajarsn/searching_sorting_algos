const fs = require('fs');
const path = require('path');
function appendFile(path,data){
    return fs.appendFile(path,data,err => {
        if(err) throw err;
    });
}

async function generateNumbersAndAppend(){
    // data = "\n";
    // for(var i = 0; i < 1000000; i++)
        // data += i+" ";
    var p = path.join(__dirname,"input.txt");
    console.log('file at path ',p);
    // await appendFile(p,data);
    // console.log('sorted numbers appended to input.txt');
    let data = "";
    for(var i = 0; i < 9000001; i++){
        var r = Math.random();
        r = Math.floor(r*1001);
        data += r+" ";
    }
    await appendFile(p,data);
    console.log('random order numbers appended to input.txt');
}
generateNumbersAndAppend();