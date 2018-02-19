

class sensor{
  uint32_t type;
  uint8_t size;
  uint8_t* lengths;
  void** data;
};

sensor::sensor(size){
  int lengths[3]={};
  lengths = new uint8_t[size];
}

sensor::sensor(){
  int data[3]={};
  data = new float[0];
  data = new float[1];
  data = new int[2];
}

void loop_data(){
  for (int i=0, i<=8,i++){
    uint8_t* data = uint8_t* data + i;
    uint8_t* = & data_get
    data[i] = data_get
  }
}
