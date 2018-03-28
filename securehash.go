
package main  
 
import (  
	"fmt" 			//print
	"math/big"		//big int calculation
	"crypto/sha256"		//sha256 hash
	"crypto/elliptic"	//elliptic curve 
	"os"			//read adn write file
	"strings"		//string split and others
	"bufio"			//read and write buffer
	"io"
	//"time"			//calculate time
)
type point struct{
	x *big.Int
	y *big.Int
}
func big_exp(x *big.Int,e int)*big.Int{		//x^e
	
	z := new(big.Int)
	return z.Exp(x,big.NewInt(int64(e)),big.NewInt(int64(0)))
}
func x_3axb(x,a,b *big.Int)*big.Int{	//x^3+ax+b
	
	z := new(big.Int)
	z.Add(b,new(big.Int).Mul(x,a))
	return z.Add(z,big_exp(x,3))
}
func big_mod(x,p *big.Int)*big.Int{		//x mod p
	
	z := new(big.Int)
	return z.Mod(x,p)
}
func is_quadratic(x,a,b,p *big.Int)*big.Int{		//test if x is quadratic
	
	//x^3
	x_cubed := big_exp(x,3)

	// ax mod p
	a_X := new(big.Int).Mul(x, a)
	a_X.Mod(a_X, p)

	// x^3+ax
	y_squared := new(big.Int).Add(x_cubed, a_X)

	// x^3+ax+b mod p
	y_squared.Add(y_squared, b)
	y_squared.Mod(y_squared, p)
	
	//get the square root of it
	res := new(big.Int).ModSqrt(y_squared, p)
	if(res==nil){
		return nil
	}
	res.Mod(res,p)
	return res		//return res mod p
}
func secure_hash(w string,a,b,p *big.Int)*point{
	var hashChannel = make(chan []byte, 1)
	sum := sha256.Sum256([]byte(w))		//hash the string

	hashChannel <- sum[:] 			//turn byte[32] into byte[]
	x := new(big.Int)
	x.SetBytes(<-hashChannel) 		//turn hash value into big int
	x.Mod(x,p)				// mod p
	
	for is_quadratic(x,a,b,p)==nil{	//if y^2 !≡ x^3+ax+b (mod p)
		x.Add(x,big.NewInt(int64(1)))	//x=x+1	
	}

	y:=is_quadratic(x,a,b,p)		//y=sqrt(x^3+ax+b)
	po := &point{x,y}			//store x and y
	return po
} 
func main() {
	e := elliptic.P224()			//the elliptic curve 
	a:=new(big.Int)
	a.SetString("-3",10)			//a=-3,the param of curve
	po := new(point)			//new a point object
	inputFileName:=os.Args[1]		//read the input file name from first parameter
	outputFileName:=os.Args[2]		//read the output file name from second parameter
	inputFile, errI := os.Open(inputFileName)	//open the file
	outputFile, errO :=os.OpenFile(outputFileName, os.O_WRONLY|os.O_CREATE,0666)
	if errI != nil || errO != nil{
		fmt.Println("Open file error!")
		return
	}
	
	defer inputFile.Close()			//Automatically close file while program closing
	defer outputFile.Close()		//Automatically close file while program closing
	inputReader := bufio.NewReader(inputFile)//input buffer
	outputWriter := bufio.NewWriter(outputFile)//output buffer
	i:=1
	//rank := new(big.Int)
	//start:=time.Now()			//the start time
	//read the file 
	for {
		inputString, Error := inputReader.ReadString('\n')	//read until '\n'
		
		if Error == io.EOF {	//read the file end
			fmt.Println("file end.")
			break
		}
		inputString = strings.TrimRight(inputString, "\r\n")	//remove the '\n'
		//ranktmp := new(big.Int)
		for index, element := range strings.Split(inputString," "){ //split inputString by " "
			
			if index == 0 || index ==1 {
				continue //UID and space
			}
			//ranktmp.SetString(element,10)
			
			po=secure_hash(element,a,e.Params().B,e.Params().P)	//secure hash the string
			outputWriter.WriteString(fmt.Sprintf("%x ",elliptic.Marshal(e,po.x,po.y)))//turn the point into special form			
						
		}
		outputWriter.WriteString("\n")
		//fmt.Printf("Line: %d finished.\n",i)
		i = i +1	
	}
	//end:=time.Now()			//the end time

	//fmt.Println("The secure hash of "+inputFileName+" is finished.")
	//fmt.Printf("Total time: %f s\n", float32(end.Sub(start).Nanoseconds()) / 1000000000)
	outputWriter.Flush()
	
}  
