var fs = require('fs');
var addon = require('bindings')('emf2svg-node.node')

var image = fs.readFileSync('./image007.emz').toString('binary');
console.log(addon.convert(image))
