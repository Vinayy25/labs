close all;
clear all;

%huffman code
message ='aabbcccddee'
l = length(message);
[x y z]= unique(message);
freq = histc(z,1:numel(x));
sym = regex(x,'.','match');
o= num2cell(freq);
k = length(sym);
for i = 1:k
    p(i) = 0;
    p(i) = o{i}/l;
end
[dict , avglen] = huffmandict(sym,p);

for i = 1:k
   iict{i,:}
end
hcode = huffmanenco(message,dict);
dhsig = huffmandeco(hcode,dict);

