var fs = require('fs');
var path = require('path');
var addon = require('bindings')('emf2svg-node.node')

var image = Buffer.from(fs.readFileSync('./sample-input.emz'), { encoding: 'ascii' });
// console.log(image);
console.log(addon.convert(image));
