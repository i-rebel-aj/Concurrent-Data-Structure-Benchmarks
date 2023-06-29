const crypto = require('crypto');
const fs = require('fs');
const args = process.argv.slice(2);
let randomString
const max_strings=Number(args[0])
for(let i=0;i<max_strings;i++){
    if(!randomString){
        randomString= crypto.randomBytes(16).toString('hex') + (i===max_strings-1?'':'\n') ;
    }else{
        randomString+= crypto.randomBytes(16).toString('hex') + (i===max_strings-1?'':'\n');
    }
}
fs.writeFileSync('listData.txt', randomString)
