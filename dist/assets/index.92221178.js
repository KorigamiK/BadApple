const g=function(){const o=document.createElement("link").relList;if(o&&o.supports&&o.supports("modulepreload"))return;for(const e of document.querySelectorAll('link[rel="modulepreload"]'))r(e);new MutationObserver(e=>{for(const t of e)if(t.type==="childList")for(const n of t.addedNodes)n.tagName==="LINK"&&n.rel==="modulepreload"&&r(n)}).observe(document,{childList:!0,subtree:!0});function s(e){const t={};return e.integrity&&(t.integrity=e.integrity),e.referrerpolicy&&(t.referrerPolicy=e.referrerpolicy),e.crossorigin==="use-credentials"?t.credentials="include":e.crossorigin==="anonymous"?t.credentials="omit":t.credentials="same-origin",t}function r(e){if(e.ep)return;e.ep=!0;const t=s(e);fetch(e.href,t)}};g();const y=c=>new Promise(o=>setTimeout(o,c));var h=document.getElementById("favicon");const f=document.getElementById("bad-apple"),d=f.getContext("2d");f.className="fav-canvas";const l=16,m=16;f.width=l;f.height=m;const v=c=>{const o=[],s=c.split(`
`);for(let r=0;r<Math.floor(s.length/l);r++){o.push([]);const e=o[r];for(let t=0;t<l;t++){const n=s[r*l+t].split(","),i=[];for(let a=0;a<m;a++){const u=[];for(let p=0;p<3;p++)u.push(parseInt(n[a*3+p]));i.push(u)}e.push(i)}}return o},w=()=>{h==null||h.setAttribute("href",f.toDataURL())},b=async()=>{const c=await(await fetch("/BadApple/frames.csv")).text(),o=v(c),s=d.getImageData(0,0,16,16),r=s.data;for(let a=0;a<o.length;a++){const u=o[a];for(var e=0;e<l;e++)for(var t=0;t<m;t++){var n=4*e*m+4*t,i=u[e][t];r[n]=i[0],r[n+1]=i[1],r[n+2]=i[2],r[n+3]=255}d==null||d.putImageData(s,0,0),w(),await y(200)}};b();