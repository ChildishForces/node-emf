var fs = require('fs');
var addon = require('bindings')('emf2svg-node.node')

var image = fs.readFileSync('./sample-input.emz');
// console.log(image);
console.log(addon.convert(image))
