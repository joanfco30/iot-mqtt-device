class OutputDevice: public Device {
    protected:
        uint16_t value;
    public:
        OutputDevice(uint16_t device_id):Device(device_id, OUTPUT_DEVICE_TYPE){}
        DataPack run(DataPack input);
        bool virtual shouldRun(DataPack input);
        uint16_t virtual execute(uint16_t value);
        uint16_t getValue();
};

uint16_t OutputDevice::getValue(){
    return this->value;
}

DataPack OutputDevice::run(DataPack input) {
    if(this->shouldRun(input)) {
        uint16_t op_value = input.getData(VALUE_KEY);
        this->value = this->execute(op_value);
        input.addData(DEVICE_ID_KEY, this->device_id);
        input.addData(DEVICE_TYPE_KEY, this->type);
        input.addData(VALUE_KEY, this->getValue());
    }
    return input;
}