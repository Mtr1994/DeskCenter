let myChart
let chartOption;

// 初始化
function init() {
	if (typeof qt != 'undefined')
    {
        new QWebChannel(qt.webChannelTransport, function(channel) { 
			context = channel.objects.context; 
			context.sgl_load_new_chart.connect(function(name) {
				if (name === "post") {
					addPostChart(name);
				} else if (name === "resume") {
					addResumeChart(name)
				} else {
					context.recvMsg("add", "error", "can not find this kind of chart");
				}
			});
			
			context.recvMsg("init", "success", "");
		});
    }
    else
    {
        alert("can not find qt web channel");
    }
	
	var chartDom = document.getElementById('main');
	myChart = echarts.init(chartDom);
	
	window.onresize = myChart.resize;
}

function handleDrop(event) {
	event.preventDefault();
}

function handleDragOver(event) {
	event.preventDefault();
}

// 添加 
function addPostChart(name) {
	let xAxisData = [];
	let data1 = [];
	let data2 = [];
	let data3 = [];
	let data4 = [];
	for (let i = 0; i < 10; i++) {
	  xAxisData.push('Class' + i);
	  data1.push(+(Math.random() * 2).toFixed(2));
	  data2.push(+(Math.random() * 5).toFixed(2));
	  data3.push(+(Math.random() + 0.3).toFixed(2));
	  data4.push(+Math.random().toFixed(2));
	}
	var emphasisStyle = {
	  itemStyle: {
		shadowBlur: 10,
		shadowColor: 'rgba(0,0,0,0.3)'
	  }
	};
	chartOption = {
	  legend: {
		data: ['bar', 'bar2', 'bar3', 'bar4'],
		bottom: 'bottom'
	  },
	  brush: {
		toolbox: ['rect', 'polygon', 'lineX', 'lineY', 'keep', 'clear'],
		xAxisIndex: 0
	  },
	  toolbox: {
		feature: {
		  magicType: {
			type: ['stack']
		  },
		  dataView: {}
		}
	  },
	  tooltip: {},
	  xAxis: {
		data: xAxisData,
		name: 'X Axis',
		axisLine: { onZero: true },
		splitLine: { show: false },
		splitArea: { show: false }
	  },
	  yAxis: {},
	  grid: {
		bottom: 100
	  },
	  series: [
		{
		  name: 'bar',
		  type: 'bar',
		  stack: 'one',
		  emphasis: emphasisStyle,
		  data: data1
		},
		{
		  name: 'bar2',
		  type: 'bar',
		  stack: 'one',
		  emphasis: emphasisStyle,
		  data: data2
		},
		{
		  name: 'bar3',
		  type: 'bar',
		  stack: 'two',
		  emphasis: emphasisStyle,
		  data: data3
		},
		{
		  name: 'bar4',
		  type: 'bar',
		  stack: 'two',
		  emphasis: emphasisStyle,
		  data: data4
		}
	  ]
	};
	myChart.on('brushSelected', function (params) {
	  var brushed = [];
	  var brushComponent = params.batch[0];
	  for (var sIdx = 0; sIdx < brushComponent.selected.length; sIdx++) {
		var rawIndices = brushComponent.selected[sIdx].dataIndex;
		brushed.push('[Series ' + sIdx + '] ' + rawIndices.join(', '));
	  }
	  myChart.setOption({
		title: {
		  backgroundColor: '#333',
		  text: 'SELECTED DATA INDICES: \n' + brushed.join('\n'),
		  bottom: 0,
		  right: '10%',
		  width: 100,
		  textStyle: {
			fontSize: 12,
			color: '#fff'
		  }
		}
	  });
	});
	
	console.log("AAAA");
	chartOption && myChart.setOption(chartOption);
}

// 添加 
function addResumeChart(data) {
	chartOption = {
		title: {
			text: 'Referer of a Website',
			subtext: 'Fake Data',
			left: 'center'
		  },
		  tooltip: {
			trigger: 'item'
		  },
		  legend: {
			orient: 'vertical',
			bottom: 'bottom'
		  },
		  series: [
			{
			  name: 'Access From',
			  type: 'pie',
			  radius: '50%',
			  data: [
				{ value: 1048, name: 'Search Engine' },
				{ value: 735, name: 'Direct' },
				{ value: 580, name: 'Email' },
				{ value: 484, name: 'Union Ads' },
				{ value: 300, name: 'Video Ads' }
			  ],
			  emphasis: {
				itemStyle: {
				  shadowBlur: 10,
				  shadowOffsetX: 0,
				  shadowColor: 'rgba(0, 0, 0, 0.5)'
				}
			  }
			}
		  ]
	};
	
	chartOption && myChart.setOption(chartOption);
}

// 时间转换
function formatDate (d) {
    var now = new Date(parseFloat(d));
    var year=now.getFullYear();
    var month=now.getMonth()+1;
    var date=now.getDate();
    if (month >= 1 && month <= 9) {
		month = "0" + month;
    }
    if (date >= 0 && date <= 9) {
		date = "0" + date;
    }
    var hour=now.getHours();
    var minute=now.getMinutes();
    var second=now.getSeconds();
    if (hour >= 1 && hour <= 9) {
		hour = "0" + hour;
    }
    if (minute >= 0 && minute <= 9) {
		minute = "0" + minute;
    }
    if (second >= 0 && second <= 9) {
		second = "0" + second;
    }
    return year+"-"+month+"-"+date+" "+hour+":"+minute+":"+second;
}
