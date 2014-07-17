A =[0,1;-8152557,-1427.63416];
I=[1,0;0,1];
f=[0;8152557];
f_old=[0;0];
r=[0;0];
vals=zeros(16,2);
dt=1/48000;

disp((I - 0.5*dt*A));

for k=1:length(vals)
	
	r=(I - 0.5*dt*A)\(r + 0.5*dt*(f + f_old + A*r));
	f_old=f;
	vals(k,:)=r;
end

%plot(vals(:,1));


