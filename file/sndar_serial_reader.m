step = 20;
device = serialport('/dev/cu.usbmodem141201', 9600); % 定義設備
data = zeros(step, 2, 'double'); % 初始化數據矩陣以存儲角度和值

fopen(device); % 開啟串行端口

for i = 1:step
    dataLine = fscanf(device, '%d %f'); % 讀取一行數據，期望為一個整數和一個浮點數
    if length(dataLine) == 2 % 確保讀取了兩個數值
        data(i, :) = dataLine'; % 儲存數據
    else
        warning('Expected an integer and a float value, received %d elements.', length(dataLine));
    end
end


% 度換pi
data(:,1)=data(:,1)*(2*pi/360);

fclose(device); % 關閉串行端口
delete(device); % 刪除定義的設備
clear device; % 清除設備變量

% 現在 data 矩陣中應該有完整的數據，其中 data(:,1) 是角度，data(:,2) 是對應的值

% 畫圖
polar(data(:,1),data(:,2),'bo')
